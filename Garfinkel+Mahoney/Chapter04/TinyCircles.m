//
//  TinyCircles.m
//  Chapter04
//
//  Created by Sam Krishna on 1/8/09.
//  Copyright 2009 Chaordium Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface DemoView : NSView {
    
}

- (void)drawRect:(NSRect)rect;

@end

@implementation DemoView

#define X(t)    (sin(t)+1) * width * 0.5
#define Y(t)    (cos(t)+1) * height * 0.5

- (void)drawRect:(NSRect)rect; {
    double x, y;
    
    //get the size of the app's window and view objects
    float width = self.bounds.size.width; //[self bounds].size.width;
    float height = self.bounds.size.height; //[self bounds].size.height;
    
    [[NSColor blackColor] set];     // Set drawing color to black
    NSRectFill([self bounds]);      // Fill the view with black
    
    // the following statements trace concentric circles    
    [[NSColor whiteColor] set]; // Draw the polygon with white lines

    for (x = 0, y = 0; x < width / 2 && y < height / 2; x += 25, y += 25) {
        NSRect r = NSMakeRect(x, y, width - (2 * x), height - (2 * y));
        NSBezierPath *_cPath = [NSBezierPath bezierPathWithOvalInRect:r];
        [_cPath stroke];
    }
} // end of -drawRect

- (void)windowWillClose:(NSNotification *)notification {
    [NSApp terminate:self];
}

@end

// setup performs the functions that would normally be performed by loading a nib file

void setup(void) {
    NSWindow    *myWindow;
    NSView      *myView;
    NSRect      graphicsRect;
    
    // initialize the rectangle variable
    graphicsRect = NSMakeRect(100.0, 750.0, 400.0, 400.0);
    
    myWindow = [[NSWindow alloc] initWithContentRect:graphicsRect
                                           styleMask:NSTitledWindowMask
                |NSClosableWindowMask
                |NSMiniaturizableWindowMask
                                             backing:NSBackingStoreBuffered
                                               defer:NO];
    
    [myWindow setTitle:@"Tiny Application Window"];
    
    // Create and initialize the DemoView instance
    myView = [[[DemoView alloc] initWithFrame:graphicsRect] autorelease];
    
    [myWindow setContentView:myView];
    [myWindow setDelegate:myView];
    [myWindow makeKeyAndOrderFront:nil];
}

int main(void) {
    NSAutoreleasePool *pool =[[NSAutoreleasePool alloc] init];
    
    NSApp = [NSApplication sharedApplication];
    
    setup();
    
    [NSApp run];
    
    [NSApp release];
    [pool release];
    return(EXIT_SUCCESS);
    
}