#import <Cocoa/Cocoa.h>

@interface AppController : NSObject {
    int fido;
}

- (IBAction)incrementFido:(id)sender;

@property(readwrite, assign) int fido;

@end
