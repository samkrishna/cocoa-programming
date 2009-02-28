#import <Cocoa/Cocoa.h>

@interface Foo : NSObject {
    IBOutlet NSTextField *resultField;
    IBOutlet NSTextField *sideField;

    NSUInteger sideNumber;
}

- (IBAction)generate:(id)sender;
- (IBAction)seed:(id)sender;
- (IBAction)setSideNumber:(id)sender;

@end
