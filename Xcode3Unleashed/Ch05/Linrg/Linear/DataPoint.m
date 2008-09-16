//
//  DataPoint.m
//  Linear
//
//  Created by Sam Krishna on 9/16/08.
//  Copyright 2008 Chaordium Software. All rights reserved.
//

#import "DataPoint.h"

@implementation DataPoint

@synthesize x;
@synthesize y;

// Default initializer. Sets x and y to 0.0.
- (id) init
{
    return [self initWithX: 0.0 Y: 0.0];
}
// Designated initializer (all initializers lead to this one).
- (id) initWithX: (double) xValue Y: (double) yValue
{
    if (![super init]) {
        return nil;
    }
    
    x = xValue;
    y = yValue;

    return self;
}

#pragma mark NSCoding

- (void) encodeWithCoder: (NSCoder *) coder
{
    [coder encodeDouble:x forKey: @"x"];
    [coder encodeDouble:y forKey: @"y"];
}

- (id) initWithCoder: (NSCoder *) coder
{
    [self setX:[coder decodeDoubleForKey: @"x"]];
    [self setY:[coder decodeDoubleForKey: @"y"]];
    return self;
}

@end
