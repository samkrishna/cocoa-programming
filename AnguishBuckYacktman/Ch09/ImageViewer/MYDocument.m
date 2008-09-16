#import "MYDocument.h"

@interface MYDocument (PrivateMethods)

- (void)_mySetDocumentPath:(NSString *)path;
- (void)_myLoadDocumentWithPath:(NSString *)path;
- (BOOL)_myShouldClose;
- (void)_mySaveDocumentData;

@end

@implementation MYDocument (PrivateMethods)

- (void)_mySetDocumentPath:(NSString *)path
{
    NSString    *standardPath = [path stringByExpandingTildeInPath];
    
    standardPath = [standardPath stringByStandardizingPath];
    [standardPath retain];
    [_myDocumentPath release];
    _myDocumentPath = standardPath;
    [[self documentWindow] setTitleWithRepresentedFilename:_myDocumentPath];
}

- (void)_myLoadDocumentWithPath:(NSString *)path
{
    NSImage     *imageData;

    NSAssert(![self hasEverBeenSaved], @"Attempt to load document that is already loaded.");
    if ([[NSFileManager defaultManager] fileExistsAtPath:path]) {
        imageData = [[NSImage alloc] initWithContentsOfFile:path];
        // NSLocalizedString(@"DELETE", @"Delete")
        if (!imageData) {
            NSRunAlertPanel(NSLocalizedString(@"MYFILE_OPEN_ERROR", @"File Open Error"),
                            NSLocalizedString(@"MY_FILE_OPEN_ERROR_MSG", @"File Open Error Msg"), 
                            nil, nil, nil, path);
        } else {
            [imageView setImage:imageData];
            [imageData release];
            
            [imageView setFrameSize:[[imageView image] size]];
            
            // Set path and remember the document has been saved
            _myHasEverBeenSaved = YES;
            [self _mySetDocumentPath:path];
        }
    } else {
        [[self documentWindow] setTitleWithRepresentedFilename:path];
    }    
}

- (BOOL)_myShouldClose
{
    BOOL    result = YES;
    
    if ([self isDocumentEdited]) {
        int         userChoice;
        NSString    *documentName = [[self documentWindow] title];
    
        if (!documentName) {
            documentName = [[self documentWindow] title];
        }
        
        // Document's been edited
        userChoice = NSRunAlertPanel(NSLocalizedString(@"MYDEFAULT_CLOSE_ACTION", @"Default Close Action"), 
                                     NSLocalizedString(@"MYSAVE_CHANGES", @"Save Changes"), 
                                     NSLocalizedString(@"MYSAVE", @"Save"), 
                                     NSLocalizedString(@"MYDONT_SAVE", @"Don't Save"), 
                                     NSLocalizedString(@"MYCANCEL", @"Cancel"));
        
        switch (userChoice) {
            case NSAlertDefaultReturn: {
                [self saveDocument:nil];
                result = YES;
                break;            
            }
            case NSAlertAlternateReturn: {
                result = YES;
                break;
            }
            case NSAlertOtherReturn: {
                result = NO;
                break;
            }
        }
    }
    
    return result;
}

- (void)_mySaveDocumentData
{
    NSData      *imageData = [[imageView image] TIFFRepresentation];
    
    if (![imageData writeToFile:[self documentPath] atomically:YES]) {
        NSRunAlertPanel(NSLocalizedString(@"MYFILE_SAVE_ERROR", @"Save Error"), 
                        NSLocalizedString(@"MYFILE_SAVE_ERROR_MSG", @"Save Error Msg"), 
                        nil, nil, nil, [self documentPath]);
    } else {
        [[self documentWindow] setDocumentEdited:NO];
        _myHasEverBeenSaved = YES;
    }
}

@end


@implementation MYDocument

@synthesize photo;

+ (NSArray *)documentExtensions
{
    return [NSImage imageFileTypes];
}

- (id)initWithPath:(NSString *)path;
{
    if (![super init]) {
        return nil;
    }

    [NSBundle loadNibNamed:@"ImageViewerDocument" owner:self];
    photo = [[NSData alloc] init];
    [imageView setTarget:self];
    [imageView setAction:@selector(noteImageWasDropped:)];
    [imageView setAutoresizingMask:NSViewNotSizable];
    [[imageView window] setReleasedWhenClosed:YES];
    
    if (path) {
        [self _myLoadDocumentWithPath:path];
    } else {
        [self _mySetDocumentPath:NSLocalizedString(@"MYDEFAULT_DOC_PATH", @"Default Doc Path")];
    }

    return self;
}

- (id)init
{
    return [self initWithPath:nil];
}

- (void)dealloc
{
    [photo release];
    [_myDocumentPath release];
    [super dealloc];
}

- (NSString *)documentPath;
{
    return _myDocumentPath;
}

- (BOOL)safeClose;
{
    return YES;
}

- (id)documentWindow;
{
    return [imageView window];
}

- (BOOL)hasEverBeenSaved;
{
    return _myHasEverBeenSaved;
}

- (BOOL)isDocumentEdited;
{
    return [[self documentWindow] isDocumentEdited];
}

- (IBAction)noteImageWasDropped:(id)sender
{
    [[self documentWindow] setDocumentEdited:YES];
    [imageView setFrameSize:[[imageView image] size]];
}

- (IBAction)saveDocument:(id)sender
{
    BOOL        pathExists;
    BOOL        pathIsDirectory;
    
    pathExists = [[NSFileManager defaultManager] fileExistsAtPath:[self documentPath] isDirectory:&pathIsDirectory];
    
    if (![self hasEverBeenSaved] || pathIsDirectory || ![self documentPath]) {
        [self saveDocumentAs:sender];
    } else {
        [self _mySaveDocumentData];
    }
}

- (IBAction)saveDocumentAs:(id)sender
{
    NSSavePanel     *savePanel;
    NSString        *documentDirectory = [[self documentPath] stringByDeletingLastPathComponent];
    NSString        *documentName = [[self documentPath] lastPathComponent];
    
    savePanel = [NSSavePanel savePanel];
    [savePanel setRequiredFileType:@"tiff"];
    [savePanel setTreatsFilePackagesAsDirectories:NO];
    
    if ([savePanel runModalForDirectory:documentDirectory file:documentName] == NSOKButton) {
        [self _mySetDocumentPath:[savePanel filename]];
        [self _mySaveDocumentData];
    }
}


- (BOOL)validateMenuItem:(NSMenuItem *)menuItem
{
    SEL     action = [menuItem action];
    BOOL    enableMenuItem = NO;
    
    if (action == @selector(saveDocument:)) {
        enableMenuItem = [self isDocumentEdited] || ![self hasEverBeenSaved];
    } else if (action == @selector(saveDocumentAs:)) {
        enableMenuItem = YES;
    }
    
    return enableMenuItem;
}

// Window delegate methods
- (BOOL)windowShouldClose:(id)sender;
{
    return [self _myShouldClose];
}

- (void)windowWillClose:(NSNotification *)notification;
{
    imageView = nil;
    [NSApp sendAction:@selector(documentWillClose:) to:nil from:self];
}

- (void)windowDidBecomeKey:(NSNotification *)notification;
{
    [NSApp sendAction:@selector(makeDocumentActive:) to:nil from:self];
}


@end
