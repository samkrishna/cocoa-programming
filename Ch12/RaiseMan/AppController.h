//
//  AppController.h
//  RaiseMan
//
//  Created by Sam Krishna on 8/21/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class PreferenceController;

@interface AppController : NSObject {
    PreferenceController *preferenceController;
    IBOutlet NSPanel *aboutPanel;
}

- (IBAction)showPreferencePanel:(id)sender;
- (IBAction)showAboutPanel:(id)sender;

@end
