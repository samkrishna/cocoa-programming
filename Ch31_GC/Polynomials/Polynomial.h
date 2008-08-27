//
//  Polynomial.h
//  Polynomials
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface Polynomial : NSObject {
    __strong CGFloat * terms;
    int termCount;
    __strong CGColorRef color;
}
- (float)valueAt:(float)x;
- (void)drawInRect:(CGRect)b
         inContext:(CGContextRef)ctx;
- (CGColorRef)color;
@end
