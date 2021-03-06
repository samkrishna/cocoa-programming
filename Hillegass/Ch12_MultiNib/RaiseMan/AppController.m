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

@end