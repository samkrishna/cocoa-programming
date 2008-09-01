#import <Cocoa/Cocoa.h>

@interface StretchView : NSView {
    NSBezierPath *path;
    NSImage *image;
    float opacity;
    NSPoint downPoint;
    NSPoint currentPoint;
    NSTimer *timer;
}

@property (readwrite) float opacity;

- (void)setImage:(NSImage *)newImage;
- (NSPoint)randomPoint;
- (NSRect)currentRect;
- (void)timedMouseDragged:(NSTimer *)aTimer;

@end
