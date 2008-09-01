//
//  OvalView.m
//  OvalFun
//
//  Created by Sam Krishna on 8/22/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "OvalView.h"
#import "MyDocument.h"

@implementation OvalView

@synthesize path;

#pragma mark NSView Overrides

- (void)drawRect:(NSRect)rect
{
    NSRect bounds = [self bounds];
    id doc = [[[self window] windowController] document];
    [[NSColor blueColor] set];
    [NSBezierPath fillRect:bounds];
    [[NSColor whiteColor] set];
    [path stroke];
    
    NSLog(@"In -drawRect:");
    NSLog(@"Number of objects in [doc ovals]: %d", [[doc ovals] count]);
    for (NSBezierPath *p in [doc ovals]) {
        [p fill];
    }
    
    if (!NSIsEmptyRect([self currentRect])) {
        [[NSBezierPath bezierPathWithOvalInRect:[self currentRect]] fill];
    }
}

- (id)initWithFrame:(NSRect)rect {
    if (![super initWithFrame:rect])
        return nil;
    
    // Create a path object
    if (!path) {
        // Seed the random # generator (this probably could be moved to MyDocument)
        srandom(time(NULL));
        path = [[NSBezierPath alloc] init];
        [path setLineWidth:3.0];
        NSPoint p = [self randomPoint];
        [path moveToPoint:p];
        int i;
        
        for (i = 0; i < 15; i++) {
            p = [self randomPoint];
            [path curveToPoint:p controlPoint1:[self randomPoint] controlPoint2:[self randomPoint]];
        }
    }

    [path closePath];        
    return self;
}

- (void)dealloc {
    [path release];
    [super dealloc];
}

#pragma mark Housekeeping

- (NSRect)currentRect
{
    float minX = MIN(downPoint.x, currentPoint.x);
    float maxX = MAX(downPoint.x, currentPoint.x);
    float minY = MIN(downPoint.y, currentPoint.y);
    float maxY = MAX(downPoint.y, currentPoint.y);
    return NSMakeRect(minX, minY, maxX-minX, maxY-minY);
}

// randomPoint returns a random point inside the view
- (NSPoint)randomPoint {
    NSPoint result;
    NSRect r = [self bounds];
    result.x = r.origin.x + random() % (int)r.size.width;
    result.y = r.origin.y + random() % (int)r.size.height;
    return result;
}

#pragma mark Events

- (void)mouseDown:(NSEvent *)event
{
    NSPoint p = [event locationInWindow];
    downPoint = [self convertPoint:p fromView:nil];
    currentPoint = downPoint;
    [self setNeedsDisplay:YES];
}

- (void)mouseDragged:(NSEvent *)event
{
    NSPoint p = [event locationInWindow];
    currentPoint = [self convertPoint:p fromView:nil];
    [self autoscroll:event];
    [self setNeedsDisplay:YES];
}

- (void)mouseUp:(NSEvent *)event
{
    NSPoint p = [event locationInWindow];
    currentPoint = [self convertPoint:p fromView:nil];
    id doc = [[[self window] windowController] document];
    if (!NSIsEmptyRect([self currentRect])) {
        [doc addMyOval:[NSBezierPath bezierPathWithOvalInRect:[self currentRect]]];
        currentPoint = downPoint; // Add an extra line to create an empty rect
    }
}

@end
