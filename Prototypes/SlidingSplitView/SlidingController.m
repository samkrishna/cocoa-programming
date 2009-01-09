//
//  SlidingController.m
//  SlidingSplitView
//
//  Created by Sam Krishna on 1/9/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import "SlidingController.h"


@implementation SlidingController

- (id)init
{
    if (![super init])
        return nil;
    
    return self;
}

- (void)dealloc
{
    [super dealloc];
}

- (IBAction)toggleSplitDisplay:(id)sender
{
	NSSize newSize = [detailSplit frame].size;
	
	[NSAnimationContext beginGrouping];
	[[NSAnimationContext currentContext] setDuration:.25];
	
	if ([sender selectedSegment] == 1)
    {
		[[theLowerSubView animator] setFrameSize:newSize];
		newSize.height = 2;
		[[theUpperSubView animator] setFrameSize:newSize];
	}
	else if ([sender selectedSegment] == 0)
    {
		[[theUpperSubView animator] setFrameSize:newSize];
		newSize.height = 0;
		[[theLowerSubView animator] setFrameSize:newSize];
	}
	
	[NSAnimationContext endGrouping];
}

@end
