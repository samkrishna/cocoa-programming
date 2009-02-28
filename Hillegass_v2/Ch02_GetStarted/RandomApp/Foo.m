#import "Foo.h"

@implementation Foo

- (id)init
{
    NSLog(@"Firing -init");
    if (![super init])
        return nil;
    
    sideNumber = 6;
    
    return self;
}

- (void)awakeFromNib
{
    NSLog(@"Firing -awakeFromNib");
    [sideField setIntValue:sideNumber];
}

- (IBAction)generate:(id)sender
{
    // Generate a number between 1 and 100 inclusive
    int generated;
    sideNumber = abs([sideField intValue]);
    [sideField setIntValue:sideNumber];
    generated = (random() % sideNumber) + 1;
    
    NSLog(@"generated = %d", generated);
    
    // Ask the text field to change what it is displaying
    [resultField setIntValue:generated];
}

- (IBAction)seed:(id)sender {
    // Seed the random number generator with the time
    srandom(time(NULL));
    [resultField setStringValue:@"Generator seeded"];
}

- (IBAction)setSideNumber:(id)sender {
    sideNumber = abs([sideField intValue]);
    [sideField setIntValue:sideNumber];
}

@end
