//
//  SlidingController.h
//  SlidingSplitView
//
//  Created by Sam Krishna on 1/9/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface SlidingController : NSObject {
    IBOutlet NSSplitView *detailSplit;
    IBOutlet NSView *theLowerSubView;
    IBOutlet NSView *theUpperSubView;
}

- (IBAction)toggleSplitDisplay:(id)sender;

@end
