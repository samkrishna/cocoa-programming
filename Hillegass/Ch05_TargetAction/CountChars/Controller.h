#import <Cocoa/Cocoa.h>

@interface Controller : NSObject {
    IBOutlet id label;
    IBOutlet id textField;
}
- (IBAction)countChars:(id)sender;
@end
