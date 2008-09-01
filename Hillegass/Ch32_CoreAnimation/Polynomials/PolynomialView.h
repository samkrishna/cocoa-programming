//
//  PolynomialView.h
//  Polynomials
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class CAAnimation;

@interface PolynomialView : NSView {
    NSMutableArray *polynomials;
    BOOL blasted;
}
- (IBAction)createNewPolynomial:(id)sender;
- (IBAction)deleteRandomPolynomial:(id)sender;
- (IBAction)blastem:(id)sender;

- (NSPoint)randomOffViewPosition;
- (void)animationDidStop:(CAAnimation *)anim finished:(BOOL)flag;

@end