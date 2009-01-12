//
//  SlidingController.h
//  SlidingSplitView
//
//  Created by Sam Krishna on 1/9/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class SlidingSplitView;

@interface SlidingController : NSObject {
    IBOutlet SlidingSplitView *detailSplit;
    IBOutlet NSView *theLowerSubView;
    IBOutlet NSView *theUpperSubView;
    IBOutlet NSButton *disclosureButton;
}

- (IBAction)toggleSplitDisplay:(id)sender;
- (IBAction)toggleDisclosureDisplay:(id)sender;
@end
