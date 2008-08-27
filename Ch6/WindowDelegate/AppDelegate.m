#import "AppDelegate.h"

@implementation AppDelegate

- (void)awakeFromNib {
    [window setDelegate:self];
    NSLog(@"-awakeFromNib");
}

- (id)init {
    [super init];
    NSLog(@"-init");
    return self;
}

- (BOOL)respondsToSelector:(SEL)aSelector
{
    NSString *methodName = NSStringFromSelector(aSelector);
    NSLog(@"respondsToSelector:%@", methodName);
    return [super respondsToSelector:aSelector];
}

- (NSSize)windowWillResize:(NSWindow *)sender 
                    toSize:(NSSize)frameSize {
    NSSize newSize;
    newSize.width = frameSize.width;
    newSize.height = 2 * frameSize.width;
    return newSize;
}

@end
