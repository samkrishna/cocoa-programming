//
//  AppController.m
//  SpeakLine
//
//  Created by Sam Krishna on 5/7/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "AppController.h"


@implementation AppController

- (id)init {
    [super init];
    NSLog(@"-init");
    
    speechSynth = [[NSSpeechSynthesizer alloc] initWithVoice:nil];
    return self;
}

- (IBAction)sayIt:(id)sender; {
    NSString *string = [textField stringValue];
    
    // Is the string zero-length?
    if ([string length] == 0) {
        NSLog(@"string from %@ is zero length", textField);
    }
    
    [speechSynth startSpeakingString:string];
    NSLog(@"Have started to say: %@", string);
}

- (IBAction)stopIt:(id)sender; {
    NSLog(@"Stopping");
    [speechSynth stopSpeaking];
}

@end
