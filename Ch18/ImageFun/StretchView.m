#import "StretchView.h"

@implementation StretchView

- (void)drawRect:(NSRect)rect
{
    NSRect bounds = [self bounds];
    [[NSColor greenColor] set];
    [NSBezierPath fillRect:bounds];
    [[NSColor whiteColor] set];
    [path stroke];
    if (image) {
        NSLog(@"From -drawRect:");
        NSRect imageRect;
        imageRect.origin = NSZeroPoint;
        imageRect.size = [image size];
        NSRect drawingRect = [self currentRect];
        [image drawInRect:drawingRect
                 fromRect:imageRect
                operation:NSCompositeSourceOver
                 fraction:opacity];
    }
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
    opacity = 1.0;
    return self;
}

- (void)dealloc {
    [path release];
    [image release];
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

#pragma mark Accessors

- (void)setImage:(NSImage *)newImage
{
    [newImage retain];
    
    [image release];
    image = newImage;
    NSSize imageSize = [newImage size];
    downPoint = NSZeroPoint;
    currentPoint.x = downPoint.x + imageSize.width;
    currentPoint.y = downPoint.y + imageSize.height;
    [self setNeedsDisplay:YES];
}

- (float)opacity
{
    return opacity;
}

- (void)setOpacity:(float)x
{
    opacity = x;
    [self setNeedsDisplay:YES];
}

- (NSRect)currentRect
{
    float minX = MIN(downPoint.x, currentPoint.x);
    float maxX = MAX(downPoint.x, currentPoint.x);
    float minY = MIN(downPoint.y, currentPoint.y);
    float maxY = MAX(downPoint.y, currentPoint.y);
    
    return NSMakeRect(minX, minY, maxX-minX, maxY-minY);
}

#pragma mark Events

- (void)mouseDown:(NSEvent *)event
{
    NSPoint p = [event locationInWindow];
    downPoint = [self convertPoint:p fromView:nil];
    currentPoint = downPoint;
    
    if (!timer) {
        timer = [[NSTimer scheduledTimerWithTimeInterval:0.05
                                                  target:self
                                                selector:@selector(timedMouseDragged:)
                                                userInfo:nil
                                                 repeats:YES] retain];
        
    }
    
    [self setNeedsDisplay:YES];
}

- (void)timedMouseDragged:(NSTimer *)aTimer {
    NSPoint p = [[NSApp currentEvent] locationInWindow];
    currentPoint = [self convertPoint:p fromView:nil];
    [self autoscroll:[NSApp currentEvent]];
    [self setNeedsDisplay:YES];
}

- (void)mouseUp:(NSEvent *)event
{
    NSPoint p = [event locationInWindow];
    currentPoint = [self convertPoint:p fromView:nil];
    [timer invalidate];
    [timer release];
    timer = nil;
    [self setNeedsDisplay:YES];
}


@end
