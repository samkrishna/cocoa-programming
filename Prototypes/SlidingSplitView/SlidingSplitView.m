//
//  SlidingSplitView.m
//  SlidingSplitView
//
//  Created by Sam Krishna on 1/12/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import "SlidingSplitView.h"

// Wrote a quick subclass to finesse the issues with the
// divider thickness.
// This is **very loosely** patterned after AMSplitView
// which is much more complex.

@implementation SlidingSplitView

@synthesize useSpecialDivider;

- (id)initWithFrame:(NSRect)frame {
    self = [super initWithFrame:frame];
    if (self)
    {
        // Initialization code here.
        useSpecialDivider = NO;
        specialDividerHeight = 1.0f;
    }
    
    return self;
}

- (void)drawRect:(NSRect)rect {
    // Drawing code here.
    [super drawRect:rect];
}

- (CGFloat)dividerThickness
{
    if (useSpecialDivider == YES)
        return specialDividerHeight;
    else
        return 9.0f;
}

@end
