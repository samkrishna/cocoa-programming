//
//  OvalView.h
//  OvalFun
//
//  Created by Sam Krishna on 8/22/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface OvalView : NSView
{
    NSPoint downPoint;
    NSPoint currentPoint;
    NSBezierPath *path;
}

@property (retain) NSBezierPath *path;

- (NSRect)currentRect;
- (NSPoint)randomPoint;

- (void)setPath:(NSBezierPath *)path;
- (NSBezierPath *)path;

@end
