//
//  AppController.m
//  RaiseMan
//
//  Created by Sam Krishna on 8/21/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "AppController.h"
#import "PreferenceController.h"

@implementation AppController

+ (void)initialize
{
    // Create a dictionary
    NSMutableDictionary *defaultValues = [NSMutableDictionary dictionary];
    
    // Archive the color object
    NSData *colorAsData = [NSKeyedArchiver archivedDataWithRootObject:[NSColor yellowColor]];
    
    // Put defaults in the dictionary
    [defaultValues setObject:colorAsData forKey:BNRTableBgColorKey];
    [defaultValues setObject:[NSNumber numberWithBool:YES]
                      forKey:BNREmptyDocKey];
    
    // Register the dictionary of defaults
    [[NSUserDefaults standardUserDefaults] registerDefaults: defaultValues];
    NSLog(@"registered defaults: %@", defaultValues);
}

- (IBAction)showPreferencePanel:(id)sender
{
    // Is preferenceController nil?
    if (!preferenceController) {
        preferenceController = [[PreferenceController alloc] init];
    }
    NSLog(@"showing %@", preferenceController);
    [preferenceController showWindow:self];
}

- (IBAction)showAboutPanel:(id)sender; {
    BOOL successful = [NSBundle loadNibNamed:@"AboutPanel" owner:self];
    [aboutPanel makeKeyWindow];
    NSLog(@"Did the nib load successfully? %d", successful);
}

- (BOOL)applicationShouldOpenUntitledFile:(NSApplication *)sender
{
    NSLog(@"applicationShouldOpenUntitledFile:");
    return [[NSUserDefaults standardUserDefaults]
            boolForKey:BNREmptyDocKey];
}

@end