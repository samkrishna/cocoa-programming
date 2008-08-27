//
//  BigLetterView.m
//  BigLetterView
//
//  Created by Sam Krishna on 8/23/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "BigLetterView.h"


@implementation BigLetterView

- (id)initWithFrame:(NSRect)rect
{
    if (![super initWithFrame:rect])
        return nil;
    
    NSLog(@"initializing view");
    bgColor = [[NSColor blueColor] retain];
    string = @" ";
    return self;
}

- (void)dealloc
{
    [bgColor release];
    [string release];
    [super dealloc];
}

- (void)drawRect:(NSRect)rect
{
    NSRect bounds = [self bounds];
    [bgColor set];
    [NSBezierPath fillRect:bounds];
    
    // Am I the window's first responder?
    if (([[self window] firstResponder] == self) &&
        [NSGraphicsContext currentContextDrawingToScreen]) {
        [NSGraphicsContext saveGraphicsState];
        NSSetFocusRingStyle(NSFocusRingOnly);
        [NSBezierPath fillRect:bounds];
        [NSGraphicsContext restoreGraphicsState];
    }
}

- (BOOL)isOpaque
{
    return YES;
}

#pragma mark First Responder methods

- (BOOL)acceptsFirstResponder
{
    NSLog(@"Accepting");
    return YES;
}

- (BOOL)resignFirstResponder
{
    NSLog(@"Resigning");
    [self setKeyboardFocusRingNeedsDisplayInRect:[self bounds]];
    return YES;
}

- (BOOL)becomeFirstResponder
{
    NSLog(@"Becoming");
    [self setNeedsDisplay:YES];
    return YES;
}

#pragma mark Event methods

- (void)keyDown:(NSEvent *)event
{
    [self interpretKeyEvents:[NSArray arrayWithObject:event]];
}

- (void)insertText:(NSString *)input
{
    // Set string to be what the user typed
    [self setString:input];
}

- (void)insertTab:(id)sender
{
    [[self window] selectKeyViewFollowingView:self];
}

// Be careful with capitalization here "backtab" is considered
// one word.
- (void)insertBacktab:(id)sender
{
    [[self window] selectKeyViewPrecedingView:self];
}
- (void)deleteBackward:(id)sender
{
    [self setString:@" "];
}

- (void)viewDidMoveToWindow
{
    int options = NSTrackingMouseEnteredAndExited |
    NSTrackingActiveAlways |
    NSTrackingInVisibleRect;
    NSTrackingArea *ta;
    ta = [[NSTrackingArea alloc] initWithRect:NSZeroRect
                                      options:options
                                        owner:self
                                     userInfo:nil];
    [self addTrackingArea:ta];
    [ta release];
}

- (void)mouseEntered:(NSEvent *)theEvent
{
    NSLog(@"Entered view");
//    isHighlighted = YES;
//    [self setNeedsDisplay:YES];
}

- (void)mouseExited:(NSEvent *)theEvent
{
    NSLog(@"Exited view");
//    isHighlighted = NO;
//    [self setNeedsDisplay:YES];
}


#pragma mark Accessors

- (void)setBgColor:(NSColor *)c
{
    [c retain];
    [bgColor release];
    bgColor = c;
    [self setNeedsDisplay:YES];
}

- (NSColor *)bgColor
{
    return bgColor;
}

- (void)setString:(NSString *)c
{
    c = [c copy];
    [string release];
    string = c;
    NSLog(@"The string is now %@", string);
}

- (NSString *)string
{
    return string;
}

@end
