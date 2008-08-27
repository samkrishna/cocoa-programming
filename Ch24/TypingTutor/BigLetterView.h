//
//  BigLetterView.h
//  BigLetterView
//
//  Created by Sam Krishna on 8/23/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface BigLetterView : NSView
{
    NSColor *bgColor;
    NSString *string;
    NSMutableDictionary *attributes;
    NSEvent *mouseDownEvent;
    BOOL isBold;
    BOOL isOblique;
    BOOL highlighted;
}

- (void)prepareAttributes;
- (void)drawStringCenteredIn:(NSRect)r;
- (IBAction)savePDF:(id)sender;
- (NSShadow *)defaultShadow;
- (IBAction)toggleBold:(id)sender;
- (IBAction)toggleItalics:(id)sender;

- (IBAction)cut:(id)sender;
- (IBAction)copy:(id)sender;
- (IBAction)paste:(id)sender;


@property (retain, readwrite) NSColor *bgColor;
@property (copy, readwrite) NSString *string;

@end