//
//  MyDocument.h
//  OvalFun
//
//  Created by Sam Krishna on 8/22/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//


#import <Cocoa/Cocoa.h>
@class OvalView;

@interface MyDocument : NSDocument
{
    IBOutlet OvalView *ovalView;
    NSBezierPath *path;
    NSMutableArray *ovals;
}

@property (readwrite) NSBezierPath *path;
@property (readwrite) NSMutableArray *ovals;

@end
