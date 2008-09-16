#import <Cocoa/Cocoa.h>

@interface MYDocument : NSObject {
    IBOutlet NSImageView *imageView;
    
    NSData      *photo;
    NSString    *_myDocumentPath;
    BOOL        _myHasEverBeenSaved;
}

@property (readwrite, assign) NSData *photo;


- (IBAction)noteImageWasDropped:(id)sender;
- (IBAction)saveDocument:(id)sender;
- (IBAction)saveDocumentAs:(id)sender;

+ (NSArray *)documentExtensions;

- (id)initWithPath:(NSString *)path;
- (id)init;

- (NSString *)documentPath;
- (BOOL)safeClose;

- (id)documentWindow;

- (BOOL)hasEverBeenSaved;
- (BOOL)isDocumentEdited;


// Window delegate methods
- (BOOL)windowShouldClose:(id)sender;
- (void)windowWillClose:(NSNotification *)notification;
- (void)windowDidBecomeKey:(NSNotification *)notification;

@end
