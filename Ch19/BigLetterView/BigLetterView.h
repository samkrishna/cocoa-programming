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
    BOOL isHighlighted;
}

@property (retain, readwrite) NSColor *bgColor;
@property (copy, readwrite) NSString *string;

@end