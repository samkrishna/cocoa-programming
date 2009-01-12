//
//  SlidingController.m
//  SlidingSplitView
//
//  Created by Sam Krishna on 1/9/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import "SlidingController.h"
#import "SlidingSplitView.h"

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
    NSLog(@"newSize = %@", NSStringFromSize(newSize));

	[NSAnimationContext beginGrouping];
	[[NSAnimationContext currentContext] setDuration:.25];
	
	if ([sender selectedSegment] == 1)
    {
		[[theLowerSubView animator] setFrameSize:newSize];
		newSize.height = 0;
        NSLog(@"Shrinking the upper view : newSize = %@", NSStringFromSize(newSize));
        
        // This is awesome! Be sure to read the docs for NSAnimatablePropertyContainer Protocol Reference
        // You can basically animate anything on an NSView or an NSWindow (YAAAY!)
        // at least, I think you can...
		[[theUpperSubView animator] setFrameSize:newSize];
	}
	else if ([sender selectedSegment] == 0)
    {
		[[theUpperSubView animator] setFrameSize:newSize];
		newSize.height = 0;
        NSLog(@"Shrinking the lower view : newSize = %@", NSStringFromSize(newSize));
		[[theLowerSubView animator] setFrameSize:newSize];
	}
	
	[NSAnimationContext endGrouping];
}

- (IBAction)toggleDisclosureDisplay:(id)sender
{
	NSSize newSize = [detailSplit frame].size;
    
	[NSAnimationContext beginGrouping];
	[[NSAnimationContext currentContext] setDuration:.25];

    if ([sender state] == NSOnState)
    {
        newSize.height = newSize.height / 2;
		[[theLowerSubView animator] setFrameSize:newSize];
        NSLog(@"Shrinking the upper view : newSize = %@", NSStringFromSize(newSize));
        
        // This is awesome! Be sure to read the docs for NSAnimatablePropertyContainer Protocol Reference
        // You can basically animate anything on an NSView or an NSWindow (YAAAY!)
        // at least, I think you can...
        
        // Change the divider thickness to normal
        [detailSplit setUseSpecialDivider:NO];
		[[theUpperSubView animator] setFrameSize:newSize];
    }
    else if ([sender state] == NSOffState)
    {
		[[theUpperSubView animator] setFrameSize:newSize];
		newSize.height = 0;
        
        NSLog(@"Shrinking the lower view : newSize = %@", NSStringFromSize(newSize));
        NSLog(@"Also changing the divider thickness to disappear it");
        [detailSplit setUseSpecialDivider:YES];
		[[theLowerSubView animator] setFrameSize:newSize];
	}

    [NSAnimationContext endGrouping];
}


@end
