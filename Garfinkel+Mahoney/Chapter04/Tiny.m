#import <Cocoa/Cocoa.h>

@interface DemoView : NSView {
    
}

- (void)drawRect:(NSRect)rect;

@end

@implementation DemoView

#define X(t)    (sin(t)+1) * width * 0.5
#define Y(t)    (cos(t)+1) * height * 0.5

- (void)drawRect:(NSRect)rect; {
    double f, g;
    double const pi = 2 * acos(0.0);
    
    int n = 12;     // # of sides of the polygon
    
    //get the size of the app's window and view objects
    float width = self.bounds.size.width; //[self bounds].size.width;
    float height = self.bounds.size.height; //[self bounds].size.height;
    
    [[NSColor blackColor] set];     // Set drawing color to black
    NSRectFill([self bounds]);      // Fill the view with black
    
    // the following statements trace two polygons with n sides
    // and connect all of the vertices with lines
    
    [[NSColor whiteColor] set]; // Draw the polygon with white lines
    
    for (f = 0; f < 2 * pi; f += 2 * pi/ n) {
        for (g = 0; g < 2 * pi; g+= 2 * pi / n) {
            NSPoint p1 = NSMakePoint(X(f), Y(f));
            NSPoint p2 = NSMakePoint(X(g), Y(g));
            [NSBezierPath strokeLineFromPoint:p1 toPoint:p2];
        }
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