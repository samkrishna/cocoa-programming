#import "AppController.h"

@implementation AppController

@synthesize fido;

- (id)init {
    [super init];
    [self setValue:[NSNumber numberWithInt:5] forKey:@"fido"];
    NSNumber *n = [self valueForKey:@"fido"];
    NSLog(@"fido = %@", n);
    return self;
}


- (IBAction)incrementFido:(id)sender; {
    [self willChangeValueForKey:@"fido"];
    fido++;
    NSLog(@"fido is now %d", fido);
    [self didChangeValueForKey:@"fido"];
}


@end
