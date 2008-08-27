//
//  PreferenceController.m
//  RaiseMan
//
//  Created by Sam Krishna on 8/21/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "PreferenceController.h"

NSString * const BNRTableBgColorKey = @"TableBackgroundColor";
NSString * const BNREmptyDocKey = @"EmptyDocumentFlag";


@implementation PreferenceController

- (id)init
{
    if (![super initWithWindowNibName:@"Preferences"])
        return nil;
    return self;
}

- (void)windowDidLoad
{
    [colorWell setColor:[self tableBgColor]];
    [checkbox setState:[self emptyDoc]];
}

- (NSColor *)tableBgColor
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSData *colorAsData = [defaults objectForKey:BNRTableBgColorKey];
    return [NSKeyedUnarchiver unarchiveObjectWithData:colorAsData];
}

- (BOOL)emptyDoc
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    return [defaults boolForKey:BNREmptyDocKey];
}

- (IBAction)changeBackgroundColor:(id)sender
{
    NSColor *color = [colorWell color];
    NSData *colorAsData = [NSKeyedArchiver archivedDataWithRootObject:color];
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    [defaults setObject:colorAsData forKey:BNRTableBgColorKey];
}

- (IBAction)changeNewEmptyDoc:(id)sender
{
    int state = [checkbox state];
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    [defaults setBool:state forKey:BNREmptyDocKey];
}

- (IBAction)resetUserDefaults:(id)sender; {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    
    // Archive the color object
    NSData *colorAsData = [NSKeyedArchiver archivedDataWithRootObject:[NSColor yellowColor]];
    
    // Put defaults in the dictionary
    [defaults setObject:colorAsData forKey:BNRTableBgColorKey];
    [defaults setBool:YES forKey:BNREmptyDocKey];
    
    [colorWell setColor:[NSColor yellowColor]];
    [checkbox setState:YES];
}

@end
