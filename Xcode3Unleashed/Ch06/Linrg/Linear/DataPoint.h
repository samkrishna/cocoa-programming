//
//  DataPoint.h
//  Linear
//
//  Created by Sam Krishna on 9/16/08.
//  Copyright 2008 Chaordium Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface  DataPoint : NSObject <NSCoding> {
    double        x;
    double        y;
}

@property (readwrite) double x;
@property (readwrite) double y;

- (id) init;
- (id) initWithX: (double) xValue Y: (double) yValue;


@end
