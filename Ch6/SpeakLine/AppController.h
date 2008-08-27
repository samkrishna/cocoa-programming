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
    IBOutlet NSButton *stopButton;
    IBOutlet NSButton *startButton;
    IBOutlet NSTableView *tableView;
    NSArray *voiceList;
}

- (IBAction)sayIt:(id)sender;
- (IBAction)stopIt:(id)sender;

- (int)numberOfRowsInTableView:(NSTableView *)aTableView;
- (id)tableView:(NSTableView *)aTableView objectValueForTableColumn:(NSTableColumn *)aTableColumn row:(int)rowIndex;

@end
