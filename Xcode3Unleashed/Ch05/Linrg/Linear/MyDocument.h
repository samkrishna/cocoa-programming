//
//  MyDocument.h
//  Linear
//
//  Created by Sam Krishna on 9/16/08.
//  Copyright Chaordium Software 2008 . All rights reserved.
//


#import <Cocoa/Cocoa.h>

@class    Regression;

@interface MyDocument : NSDocument
{
    Regression * model;
}
- (IBAction) compute: (id) sender;

@end
