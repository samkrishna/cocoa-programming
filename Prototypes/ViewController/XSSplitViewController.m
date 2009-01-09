//
//  XSSplitViewController.m
//  View Controllers
//
//  Created by Jonathan Dann and Cathy Shive on 14/04/2008.
//
// Copyright (c) 2008 Jonathan Dann and Cathy Shive
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// If you use it, acknowledgement in an About Page or other appropriate place would be nice.
// For example, "Contains "View Conrtollers" by Jonathan Dann and Cathy Shive" will do.

#import "XSSplitViewController.h"
#import "XSOutlineViewController.h"
#import "XSTextViewController.h"

#define MIN_LEFT_PANEL_W 250.0

@implementation XSSplitViewController

// -----------------------------------
// Override the designated initialiser to add the view controllers that we want by default when the window is loaded. By doing this, calling this method (or the +defaultController) method will cause the whole view controller tree to be built.
// ------------------------------------
- (id)initWithNibName:(NSString *)name bundle:(NSBundle *)bundle windowController:(XSWindowController *)windowController;
{
	if (![super initWithNibName:name bundle:bundle windowController:windowController])
		return nil;
	XSOutlineViewController *outlineViewController = [[[XSOutlineViewController alloc] initWithNibName:@"SourceList" bundle:nil windowController:windowController] autorelease];
	XSTextViewController *textViewController = [[[XSTextViewController alloc] initWithNibName:@"TextView" bundle:nil windowController:windowController] autorelease];
	[self addChild:outlineViewController];
	[self addChild:textViewController];

	return self;
}

// -----------------------------------
// The tree has been built and all the objects in the NIB have received -init so we can then configure how the window will look.  Setting the subviews of the split view to the NSOutlineView and the NSTextView.
// ------------------------------------
- (void)awakeFromNib;
{
    NSSplitView *_view = (NSSplitView *)[self view];
    [_view setSubviews:[NSArray arrayWithObjects:
        [[[self children] objectAtIndex:0] view],
        [[[self children] objectAtIndex:1] view],
        nil]];
    [_view setDelegate:self];
}

#pragma mark NSSplitView Delegate

// The view controller owns the NIB for the split view, so can be set at the delegate of the NSSplitView. The view controller then has the job its name implies.  In the case of the split view it can tell it when to collapse, or what relative sizes the panes should be, etc....

- (void) splitView:(NSSplitView *)sender resizeSubviewsWithOldSize:(NSSize)oldSize {
	// http://www.wodeveloper.com/omniLists/macosx-dev/2003/May/msg00261.html
    // This code was used from http://snipplr.com/view/2452/resize-nssplitview-nicely/
	
	// grab the splitviews
    NSView *left = [[sender subviews] objectAtIndex:0];
    NSView *right = [[sender subviews] objectAtIndex:1];
	
    float dividerThickness = [sender dividerThickness];
	
	// get the different frames
    NSRect newFrame = [sender frame];
    NSRect leftFrame = [left frame];
    NSRect rightFrame = [right frame];
	
	// change in width for this redraw
	int	dWidth  = newFrame.size.width - oldSize.width;
	
	// ratio of the left frame width to the right used for resize speed when both panes are being resized
	float rLeftRight = (leftFrame.size.width - MIN_LEFT_PANEL_W) / rightFrame.size.width;
    
	// resize the height of the left
    leftFrame.size.height = newFrame.size.height;
    leftFrame.origin = NSMakePoint(0,0);
	
	// resize the left & right pane equally if we are shrinking the frame
	// resize the right pane only if we are increasing the frame
	// when resizing lock at minimum width for the left panel
	if(leftFrame.size.width <= MIN_LEFT_PANEL_W && dWidth < 0) {
		rightFrame.size.width += dWidth;
	} else if(dWidth > 0) {
		rightFrame.size.width += dWidth;
	} else {
		leftFrame.size.width += dWidth * rLeftRight;
		rightFrame.size.width += dWidth * (1 - rLeftRight);
	}
    
    rightFrame.size.width = newFrame.size.width - leftFrame.size.width - dividerThickness;
    rightFrame.size.height = newFrame.size.height;
    rightFrame.origin.x = leftFrame.size.width + dividerThickness;
    
    [left setFrame:leftFrame];
    [right setFrame:rightFrame];
}

@end
