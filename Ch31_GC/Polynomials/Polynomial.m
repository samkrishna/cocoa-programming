//
//  Polynomial.m
//  Polynomials
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "Polynomial.h"
#import <QuartzCore/QuartzCore.h>

// Number of segments drawn
#define HOPS (100)

// A random float between 0 and 1
#define RANDFLOAT() (random() % 128 / 128.0)

// The part of the x-y graph that will be drawn
static CGRect funcRect = {-20, -20, 40, 40};


@implementation Polynomial

// Create 'terms' and 'color' to be handled by GC
- (id)init
{
    [super init];
    // Create a color
    color = CGColorCreateGenericRGB(RANDFLOAT(), RANDFLOAT(),
                                    RANDFLOAT(), 0.5);
    
    // Put it under control of the GC
    CFMakeCollectable(color);
    
    // Create the coefficients of the polynomial between -5 and 5
    termCount = (random() % 3) + 2;
    terms = NSAllocateCollectable(termCount * sizeof(CGFloat), 0);
    
    // Set them to random values
    int i;
    for (i = 0; i < termCount; i++) {
        terms[i] = 5.0 - (random() % 100) / 10.0;
    }
    
    return self;
}
- (float)valueAt:(float)x
{
    float result = 0;
    int i;
    for (i = 0; i < termCount; i++) {
        result = (result * x) + terms[i];
    }
    return result;
}

// Draw using core graphics
- (void)drawInRect:(CGRect)b inContext:(CGContextRef)ctx
{
    NSLog(@"drawing");
    CGContextSaveGState(ctx);
    
    // Scale and translate coordinate system so drawing
    // in funcRect fills view
    CGAffineTransform tf =
    CGAffineTransformMake(b.size.width / funcRect.size.width, 0,
                          0, b.size.height / funcRect.size.height,
                          b.size.width/2, b.size.height/2);
    
    // Apply the affine transform to the graphics context
    CGContextConcatCTM(ctx, tf);
    CGContextSetStrokeColorWithColor(ctx, color);
    CGContextSetLineWidth(ctx, 0.4);
    float distance = funcRect.size.width / HOPS;
    float currentX = funcRect.origin.x;
    BOOL first = YES;
    while (currentX <= funcRect.origin.x + funcRect.size.width) {
        float currentY = [self valueAt:currentX];
        if (first) {
            CGContextMoveToPoint(ctx, currentX, currentY);
            first = NO;
        } else {
            CGContextAddLineToPoint(ctx, currentX, currentY);
        }
        currentX += distance;
    }
    CGContextStrokePath(ctx);
    
    // Remove the affine transform
    CGContextRestoreGState(ctx);
    
    
}
- (CGColorRef)color
{
    return color;
}

// Log during finalize
- (void)finalize
{
    NSLog(@"finalizing %@", self);
    [super finalize];
}

@end
