//
//  AppController.h
//  SpeakLine
//
//  Created by Sam Krishna on 5/7/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface AppController : NSObject {
    IBOutlet NSTextField *textField;
    NSSpeechSynthesizer *speechSynth;
}

- (IBAction)sayIt:(id)sender;
- (IBAction)stopIt:(id)sender;

@end
