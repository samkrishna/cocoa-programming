//
//  OvalView.m
//  OvalFun
//
//  Created by Sam Krishna on 8/22/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "OvalView.h"


@implementation OvalView

- (void)drawRect:(NSRect)rect
{
    NSRect bounds = [self bounds];
    [[NSColor blueColor] set];
    [NSBezierPath fillRect:bounds];
    [[NSColor whiteColor] set];
    [path stroke];

    for (NSBezierPath *p in ovals) {
        [p fill];
    }
    
    if ((currentPoint.x != downPoint.x) || (currentPoint.y != downPoint.y)) {
        [[NSBezierPath bezierPathWithOvalInRect:[self currentRect]] fill];
    }
}

- (id)initWithFrame:(NSRect)rect {
    if (![super initWithFrame:rect])
        return nil;
    
    if (ovals == nil) {
        ovals = [[NSMutableArray alloc] init];
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
            [path curveToPoint:p controlPoint1:[self randomPoint] controlPoint2:[self randomPoint]];
        }
        [path closePath];        
    }
    
    return self;
}

- (void)dealloc {
    [path release];
    [ovals release];
    [super dealloc];
}

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
    [ovals addObject:[NSBezierPath bezierPathWithOvalInRect:[self currentRect]]];
    [self setNeedsDisplay:YES];
}

#pragma mark NSKeyValueCoding Methods

- (NSArray *)attributeKeys; {
    return [NSArray arrayWithObjects:
            @"path",
            @"ovals",
            nil];
}

- (NSDictionary *)dictionaryWithValuesForKeys:(NSArray *)keys; {
    return [self valuesForKeys:[self attributeKeys]];
}

#pragma mark NSCoding Methods

- (id)initWithCoder:(NSCoder *)coder {
    [super initWithCoder:coder];
    [self setValuesForKeysWithDictionary:[coder decodeObject]];
    downPoint = [coder decodePointForKey:@"downPoint"];
    currentPoint = [coder decodePointForKey:@"currentPoint"];
    [self setNeedsDisplay:YES];
    return self;
}

- (void)encodeWithCoder:(NSCoder *)coder {
    [super encodeWithCoder:coder];
    [coder encodeObject:[self dictionaryWithValuesForKeys:[self attributeKeys]]];
    [coder encodePoint:downPoint forKey:@"downPoint"];
    [coder encodePoint:currentPoint forKey:@"currentPoint"];
}

@end
