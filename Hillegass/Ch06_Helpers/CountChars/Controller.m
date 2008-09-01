#import "Controller.h"

@implementation Controller
- (IBAction)countChars:(id)sender {
    NSString *value = [textField stringValue];
    [label setStringValue:[NSString stringWithFormat:@"\"%@\" has %d characters.", value, [value length]]];
}
@end
