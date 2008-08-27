//
//  PeopleView.m
//  RaiseMan
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "PeopleView.h"
#import "Person.h"

@implementation PeopleView

- (id)initWithPeople:(NSArray *)persons
{
    // Call the superclass's designated initializer with some
    // dummy frame
    [super initWithFrame:NSMakeRect(0, 0, 700, 700)];
    people = [persons copy];
    // The attributes of the text to be printed
    attributes = [[NSMutableDictionary alloc] init];
    NSFont *font = [NSFont fontWithName:@"Monaco" size:12.0];
    lineHeight = [font capHeight] * 1.7;
    [attributes setObject:font
                   forKey:NSFontAttributeName];
    return self;
}
- (void)dealloc
{
    [people release];
    [attributes release];
    [super dealloc];
}

#pragma mark Pagination

- (BOOL)knowsPageRange:(NSRange *)range
{
    NSPrintOperation *po = [NSPrintOperation currentOperation];
    NSPrintInfo *printInfo = [po printInfo];
    // Where can I draw?
    pageRect = [printInfo imageablePageBounds];
    NSRect newFrame;
    newFrame.origin = NSZeroPoint;
    newFrame.size = [printInfo paperSize];
    [self setFrame:newFrame];

    // How many lines per page?
    linesPerPage = pageRect.size.height / lineHeight;
    
    // Pages are 1-based
    range->location = 1;
    
    // How many pages will it take?
    range->length = [people count] / linesPerPage;
    if ([people count] % linesPerPage) {
        range->length = range->length + 1;
    }
    return YES;
}

- (NSRect)rectForPage:(int)i
{
    // Note the current page
    currentPage = i - 1;
    
    // Return the same page rect everytime
    return pageRect;
}

#pragma mark Drawing

// The origin of the view is at the upper-left corner
- (BOOL)isFlipped
{
    return YES;
}

- (void)drawRect:(NSRect)r
{
    NSRect nameRect;
    NSRect raiseRect;
    NSRect pageNumberRect;
    
    raiseRect.size.height = nameRect.size.height = pageNumberRect.size.height = lineHeight;
    nameRect.origin.x = pageRect.origin.x;
    nameRect.size.width = 200.0;
    raiseRect.origin.x = NSMaxX(nameRect);
    raiseRect.size.width = 100.0;
    pageNumberRect.origin.x = NSMaxX(raiseRect) + 200.0;
    pageNumberRect.size.width = 200.0;
    pageNumberRect.origin.y = pageRect.origin.y;
    
    NSString *pageString = [NSString stringWithFormat:@"Page #%d", currentPage + 1];
    [pageString drawInRect:pageNumberRect withAttributes:attributes];
    
    int i;
    for (i=0; i<linesPerPage; i++) {
        int index = (currentPage * linesPerPage) + i;
        if (index >= [people count]) {
            break;
        }
        Person *p = [people objectAtIndex:index];
        
        // Draw index and name
        nameRect.origin.y = pageRect.origin.y + (i * lineHeight);
        NSString *nameString = [NSString stringWithFormat:@"%2d %@",
                                index, [p personName]];
        [nameString drawInRect:nameRect withAttributes:attributes];
        
        raiseRect.origin.y = nameRect.origin.y;
        NSString *raiseString=[NSString stringWithFormat:@"%4.1f%%",
                               [p expectedRaise]];
        [raiseString drawInRect:raiseRect withAttributes:attributes];
    }    
}

@end
