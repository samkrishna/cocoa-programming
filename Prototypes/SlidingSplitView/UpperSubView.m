//
//  UpperSubView.m
//  SlidingSplitView
//
//  Created by Sam Krishna on 1/9/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import "UpperSubView.h"


@implementation UpperSubView

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
    [[NSColor blueColor] set];
    [[NSBezierPath bezierPathWithOvalInRect:rect] fill];
}

@end
