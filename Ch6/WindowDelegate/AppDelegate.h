#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject {
    IBOutlet id window;
}

- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)frameSize;

@end
