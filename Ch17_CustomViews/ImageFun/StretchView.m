#import "StretchView.h"

@implementation StretchView

- (void)drawRect:(NSRect)rect {
    NSRect bounds = [self bounds];
    [[NSColor greenColor] set];
    [NSBezierPath fillRect:rect];
    
    // Draw the path in white
    [[NSColor whiteColor] set];
    [path fill];
}

- (id)initWithFrame:(NSRect)rect {
    if (![super initWithFrame:rect])
        return nil;
    
    // Seed the random # generator
    srandom(time(NULL));
    
    // Create a path object
    path = [[NSBezierPath alloc] init];
    [path setLineWidth:3.0];
    NSPoint p = [self randomPoint];
    [path moveToPoint:p];
    int i;
    
    for (i = 0; i < 15; i++) {
        p = [self randomPoint];
        // [path lineToPoint:p];
        [path curveToPoint:p controlPoint1:[self randomPoint] controlPoint2:[self randomPoint]];
    }
    [path closePath];
    return self;
}

- (void)dealloc {
    [path release];
    [super dealloc];
}

// randomPoint returns a random point inside the view
- (NSPoint)randomPoint {
    NSPoint result;
    NSRect r = [self bounds];
    result.x = r.origin.x + random() % (int)r.size.width;
    result.y = r.origin.y + random() % (int)r.size.height;
    return result;
}

@end
