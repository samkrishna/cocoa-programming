//
//  XSDocumentWindowController.m
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
// If you use it, acknowledgement in an About page or other appropriate place would be nice.
// For example, "Contains "View Conrtollers" by Jonathan Dann and Cathy Shive" will do.

#import "XSDocumentWindowController.h"
#import "XSSplitViewController.h"

@implementation XSDocumentWindowController

+ (XSDocumentWindowController *)defaultController;
{
	return [[[self alloc] initWithWindowNibName:@"XSDocument"] autorelease];
}

// --------------------------------------
// After the window is loaded from the nib we create the view controller tree and set the split view as the subview of the content view.  By this time the split view has its subviews set, see XSSplitViewController's -awakeFromNib method.
// --------------------------------------
- (void)windowDidLoad;
{
	XSSplitViewController *splitViewController = [[[XSSplitViewController alloc] initWithNibName:@"SplitView" bundle:nil windowController:self] autorelease];
	[splitViewController setRepresentedObject:self.document];
	[self addViewController:splitViewController];
	[splitViewController.view setFrame:[self.window.contentView frame]];
	[self.window.contentView addSubview:splitViewController.view];
	[self.document windowControllerDidLoadNib:self]; // allow the document to do more setup
}
@end
