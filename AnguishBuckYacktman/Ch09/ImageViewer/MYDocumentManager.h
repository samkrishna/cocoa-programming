#import <Cocoa/Cocoa.h>

@interface MYDocumentManager : NSObject {
    NSMutableArray  *_myOpenDocuments;
    NSPoint         _myWindowCascadePoint;
}

- (Class)documentClass;

- (NSArray *)documentExtensions;

- (NSArray *)existingOpenDocuments;
- (id)existingOpenDocumentWithPath:(NSString *)path;
- (id)activeDocument;

- (IBAction)openDocument:(id)sender;
- (IBAction)newDocument:(id)sender;
- (IBAction)saveAllDocuments:(id)sender;

- (void)documentWillClose:(id)sender;
- (void)makeDocumentActive:(id)sender;

// App Delegate methods
- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender;
- (BOOL)application:(NSApplication *)sender openFile:(NSString *)filename;
- (BOOL)applicationShouldOpenUntitledFile:(NSApplication *)sender;
- (BOOL)applicationOpenUntitledFile:(NSApplication *)sender;

@end
