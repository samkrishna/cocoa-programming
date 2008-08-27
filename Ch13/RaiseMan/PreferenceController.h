//
//  PreferenceController.h
//  RaiseMan
//
//  Created by Sam Krishna on 8/21/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

extern NSString * const BNRTableBgColorKey;
extern NSString * const BNREmptyDocKey;

@interface PreferenceController : NSWindowController {
    IBOutlet NSColorWell *colorWell;
    IBOutlet NSButton *checkbox;
}

- (IBAction)changeBackgroundColor:(id)sender;
- (IBAction)changeNewEmptyDoc:(id)sender;
- (IBAction)resetUserDefaults:(id)sender;

- (NSColor *)tableBgColor;
- (BOOL)emptyDoc;

@end