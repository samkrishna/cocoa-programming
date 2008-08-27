//
//  PolynomialView.h
//  Polynomials
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@interface PolynomialView : NSView {
    NSMutableArray *polynomials;
}
- (IBAction)createNewPolynomial:(id)sender;
- (IBAction)deleteRandomPolynomial:(id)sender;
@end