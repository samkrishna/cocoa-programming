//
//  LowerSubView.m
//  SlidingSplitView
//
//  Created by Sam Krishna on 1/9/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import "LowerSubView.h"


@implementation LowerSubView

- (id)initWithFrame:(NSRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
        [self setNeedsDisplay:YES];
    }
    return self;
}

- (void)drawRect:(NSRect)rect {
    // Drawing code here.
    [[NSColor greenColor] set];
    NSRect _rect = NSMakeRect(rect.origin.x + 25, rect.origin.y - 25, rect.size.width - 50, rect.size.height - 50);
    //[[NSBezierPath bezierPathWithRect:_rect] fill];
    NSRectFill(_rect);
}

@end
