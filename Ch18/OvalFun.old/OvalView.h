//
//  OvalView.h
//  OvalFun
//
//  Created by Sam Krishna on 8/22/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface OvalView : NSView <NSCoding> {
    NSBezierPath *path;
    NSMutableArray *ovals;
    NSPoint downPoint;
    NSPoint currentPoint;
}

- (NSRect)currentRect;
- (NSPoint)randomPoint;

- (NSArray *)attributeKeys;
- (NSDictionary *)dictionaryWithValuesForKeys:(NSArray *)keys;

@end
