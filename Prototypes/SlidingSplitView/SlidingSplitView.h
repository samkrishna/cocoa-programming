//
//  SlidingSplitView.h
//  SlidingSplitView
//
//  Created by Sam Krishna on 1/12/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface SlidingSplitView : NSSplitView
{
    BOOL useSpecialDivider;
    CGFloat specialDividerHeight;
}

@property (readwrite) BOOL useSpecialDivider; 

@end
