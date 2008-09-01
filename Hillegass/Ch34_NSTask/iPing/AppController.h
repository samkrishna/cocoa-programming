//
//  AppController.h
//  iPing
//
//  Created by Sam Krishna on 8/26/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppController : NSObject
{
    IBOutlet NSTextView *outputView;
    IBOutlet NSTextField *hostField;
    IBOutlet NSButton *startButton;
    NSTask *task;
    NSPipe *pipe;
}

- (IBAction)startStopPing:(id)sender;
- (void)dataReady:(NSNotification *)n;
- (void)taskTerminated:(NSNotification *)note;
- (void)appendData:(NSData *)d;

@end