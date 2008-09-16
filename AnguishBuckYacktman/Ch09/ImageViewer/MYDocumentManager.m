#import "MYDocumentManager.h"
#import "MYDocument.h"

@interface MYDocumentManager (Private)

- (void)_myInitInstanceVariables;
- (NSString *)_myNextUntitledDocumentName;
- (void)_myRegisterDocument:(id)document;
- (void)_myOpenDocumentWithPath:(NSString *)path;

@end

@implementation MYDocumentManager (Private)

- (void)_myInitInstanceVariables
{
    NSRect      screenVisibleFrame = [[NSScreen mainScreen] visibleFrame];
    
    // Create an array of open documents
    _myOpenDocuments = [[NSMutableArray allocWithZone:[self zone]] init];
    
    // Set initial cascade point
    _myWindowCascadePoint = NSMakePoint(0, NSMaxY(screenVisibleFrame));
}

- (NSString *)_myNextUntitledDocumentName
{
    static int lastUntitledIndex = 1;
    NSString *result = nil;
    NSString *extension = @"";
    NSArray *documentExtensions = [self documentExtensions];
    
    if (0 < [documentExtensions count]) {
        extension = [documentExtensions lastObject];
    }
    
    do {
        [result release];
        result = [[NSString alloc] initWithFormat:@"~/%@%d.%@", NSLocalizedString(@"MYUNTITLED", @""), lastUntitledIndex++, extension];
    } while ([[NSFileManager defaultManager] fileExistsAtPath:[result stringByStandardizingPath]]);
    
    [result autorelease];
    return result;
}

- (void)_myRegisterDocument:(id)document
{
    [_myOpenDocuments addObject:document];
    
    if ([document respondsToSelector:@selector(documentWindow)]) {
        id documentWindow = [document documentWindow];
        
        // Cascade the registered document's window
        _myWindowCascadePoint = [documentWindow cascadeTopLeftFromPoint:_myWindowCascadePoint];
        
        // make registered document's window visible and key
        [documentWindow makeKeyAndOrderFront:self];
    }
}

- (void)_myOpenDocumentWithPath:(NSString *)path
{
    id newDocument = [self existingOpenDocumentWithPath:path];
    
    if (newDocument) {
        [[newDocument documentWindow] makeKeyAndOrderFront:self];
    } else {
        newDocument = [[[self documentClass] allocWithZone:[self zone]] initWithPath:path];
        
        if (newDocument) {
            NSLocalizedString(@"MYOPEN_DOCUMENT_ERROR_MSG", @"Open Error Msg");
        } else {
            [self _myRegisterDocument:newDocument];
            [newDocument release];
        }
    }
}

@end


@implementation MYDocumentManager

- (id)init
{
    if (![super init]) {
        return nil;
    }
    
    [self _myInitInstanceVariables];
    
    return self;
}

- (void)dealloc
{
    [_myOpenDocuments release];
    _myOpenDocuments = nil;
    
    [super dealloc];
}

- (void)awakeFromNib
{
    [self _myInitInstanceVariables];
}

- (Class)documentClass
{
    return [MYDocument class];
}

- (NSArray *)documentExtensions
{
    NSMutableArray  *supportedExtensions = [NSMutableArray array];
    Class           documentClass = [self documentClass];
    
    if ([documentClass respondsToSelector:@selector(documentExtensions)]) {
        [supportedExtensions addObjectsFromArray:[documentClass documentExtensions]];
    }
    
    return supportedExtensions;
}

- (NSArray *)existingOpenDocuments
{
    return _myOpenDocuments;
}

- (id)existingOpenDocumentWithPath:(NSString *)path;
{
    NSString *standardPath = [path stringByStandardizingPath];
    id result = nil;
    id currentDocument = nil;
    NSEnumerator *enumerator = [_myOpenDocuments objectEnumerator];
    
    while (!result && (currentDocument = [enumerator nextObject])) {
        if ([currentDocument respondsToSelector:@selector(documentPath)]) {
            if ([[currentDocument documentPath] isEqualToString:standardPath]) {
                result = currentDocument;
            }
        }
    }
    
    return result;
}

- (id)activeDocument;
{
    return (0 < [_myOpenDocuments count]) ? [_myOpenDocuments lastObject] : nil;
}

- (IBAction)openDocument:(id)sender;
{
    NSArray *typesArray = nil;
    NSOpenPanel *openPanel = nil;
    NSString *directory = nil;
    id activeDocument = nil;
    
    typesArray = [self documentExtensions];
    
    if (typesArray == 0) {
        typesArray = nil;
    }
    
    activeDocument = [self activeDocument];
    
    if (activeDocument && [activeDocument respondsToSelector:@selector(documentPath)]) {
        directory = [[activeDocument documentPath] stringByDeletingLastPathComponent];
    } else {
        directory = @"";
    }
    
    openPanel = [NSOpenPanel openPanel];
    [openPanel setAllowsMultipleSelection:YES];
    [openPanel setTreatsFilePackagesAsDirectories:NO];
    [openPanel setDirectory:directory];
    [openPanel setCanChooseDirectories:NO];
    [openPanel setCanChooseFiles:YES];
    [openPanel setResolvesAliases:YES];
    
    if ([openPanel runModalForTypes:typesArray] == NSOKButton) {
        NSArray *selectedPaths = [openPanel filenames];
        NSEnumerator *enumerator = [selectedPaths objectEnumerator];
        NSString *currentPath = nil;
        
        while (currentPath = [enumerator nextObject]) {
            [self _myOpenDocumentWithPath:currentPath];
        }
    }
}

- (IBAction)newDocument:(id)sender;
{
    id newDocument = nil;
    NSString *newDocumentPath = [self _myNextUntitledDocumentName];
    
    newDocument = [[[self documentClass] allocWithZone:[self zone]] initWithPath:newDocumentPath];
    
    if (!newDocument) {
        NSLog(@"MYNEW_DOCUMENT_ERROR_MSG");
        //NSLog(@"%@", NSLocalizedString(@"MYNEW_DOCUMENT_ERROR_MSG", @""));
    } else {
        [self _myRegisterDocument:newDocument];
        [newDocument release];
    }
}

- (IBAction)saveAllDocuments:(id)sender;
{
    [[self existingOpenDocuments] makeObjectsPerformSelector:@selector(saveDocument:) withObject:sender];
}

- (void)documentWillClose:(id)sender;
{
    [_myOpenDocuments removeObject:sender];
}
- (void)makeDocumentActive:(id)sender;
{
    if (0 < [_myOpenDocuments count]) {
        int index = [_myOpenDocuments indexOfObject:sender];
        
        if (index != NSNotFound) {
            [sender retain];
            [_myOpenDocuments replaceObjectAtIndex:index withObject:[_myOpenDocuments lastObject]];
            [_myOpenDocuments removeLastObject];
            [_myOpenDocuments addObject:sender];
            [sender release];
        }
    }
}

- (BOOL)validateMenuItem:(NSMenuItem *)menuItem
{
    SEL action = [menuItem action];
    BOOL enableMenuItem = NO;
    
    if (action == @selector(openDocument:) ||
        action == @selector(newDocument:)) {
        enableMenuItem = YES;
    } else if (action == @selector(saveAllDocuments:)) {
        enableMenuItem = (0 < [_myOpenDocuments count]);
    }
    
    return enableMenuItem;
}

// App Delegate methods
- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender;
{
    NSEnumerator *enumerator = nil;
    id currentDocument = nil;
    int choice;
    NSApplicationTerminateReply result = NSTerminateNow;
    BOOL foundUnsaved = NO;
    
    enumerator = [_myOpenDocuments objectEnumerator];
    while (!foundUnsaved && (currentDocument = [enumerator nextObject])) {
        if ([currentDocument respondsToSelector:@selector(isDocumentEdited)]) {
            foundUnsaved = [currentDocument isDocumentEdited];
        }
    }
    
    if (foundUnsaved) {
        choice = NSRunAlertPanel(NSLocalizedString(@"MYQUIT", @"Quit"), 
                                 NSLocalizedString(@"MYUNSAVED_DOCS_MSG", @"Unsaved Docs"), 
                                 NSLocalizedString(@"MYREVIEW_UNSAVED", @"Review Unsaved"), 
                                 NSLocalizedString(@"MYQUIT_ANYWAY", @"Quit Anyway"), 
                                 NSLocalizedString(@"MYCANCEL", @"Cancel"));
        
        if (choice == NSAlertOtherReturn) {
            result = NSTerminateCancel;
        } else if (choice != NSAlertAlternateReturn) {
            enumerator = [_myOpenDocuments objectEnumerator];
            while (result == NSTerminateNow && (currentDocument = [enumerator nextObject])) {
                if ([currentDocument respondsToSelector:@selector(safeClose)]) {
                    if (![currentDocument safeClose]) {
                        result = NSTerminateCancel;
                    }
                }
            }
        } else {
            // User chooses to quit w/o saving
        }
    }
    
    return result;
}

- (BOOL)application:(NSApplication *)sender openFile:(NSString *)filename;
{
    BOOL result = NO;
    
    if ([[self documentExtensions] containsObject:[filename pathExtension]]) {
        [self _myOpenDocumentWithPath:filename];
        result = YES;
    }
    
    return result;
}

- (BOOL)applicationShouldOpenUntitledFile:(NSApplication *)sender;
{
    return YES;
}

- (BOOL)applicationOpenUntitledFile:(NSApplication *)sender;
{
    [self newDocument:nil];
    return YES;
}


@end
