//
//  Regression.h
//  Linear
//
//  Created by Sam Krishna on 9/16/08.
//  Copyright 2008 Chaordium Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface  Regression : NSObject <NSCoding> {
    NSMutableArray *dataPoints;
    double slope;
    double intercept;
    double correlation;
    
    NSTask *linrgTask;
}

@property (assign) double slope;
@property (assign) double intercept;
@property (assign) double correlation;
@property (assign) NSMutableArray *dataPoints;

- (id) init;
- (BOOL) canCompute;
- (void) computeWithLinrg;

@end
