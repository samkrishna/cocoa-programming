//
//  AppController.m
//  SpeakLine
//
//  Created by Sam Krishna on 5/7/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "AppController.h"


@implementation AppController

- (void)awakeFromNib {
    NSString *defaultVoice = [NSSpeechSynthesizer defaultVoice];
    int defaultRow = [voiceList indexOfObject:defaultVoice];
    [tableView selectRow:defaultRow byExtendingSelection:NO];
    [tableView scrollRowToVisible:defaultRow];
}

- (id)init {
    [super init];
    NSLog(@"-init");
    
    speechSynth = [[NSSpeechSynthesizer alloc] initWithVoice:nil];
    voiceList = [[NSSpeechSynthesizer availableVoices] retain];
    [speechSynth setDelegate:self];
    return self;
}

- (void)speechSynthesizer:(NSSpeechSynthesizer *)sender
        didFinishSpeaking:(BOOL)complete
{
    NSLog(@"complete = %d", complete);
    [stopButton setEnabled:NO];
    [startButton setEnabled:YES];
    [tableView setEnabled:YES];
}

- (IBAction)sayIt:(id)sender; {
    NSString *string = [textField stringValue];
    
    // Is the string zero-length?
    if ([string length] == 0) {
        NSLog(@"string from %@ is zero length", textField);
    }
    
    [speechSynth startSpeakingString:string];
    NSLog(@"Have started to say: %@", string);
    [stopButton setEnabled:YES];
    [startButton setEnabled:NO];
    [tableView setEnabled:NO];
}

- (IBAction)stopIt:(id)sender; {
    NSLog(@"Stopping");
    [speechSynth stopSpeaking];
}

- (BOOL)respondsToSelector:(SEL)aSelector
{
    NSString *methodName = NSStringFromSelector(aSelector);
    NSLog(@"respondsToSelector:%@", methodName);
    return [super respondsToSelector:aSelector];
}

- (int)numberOfRowsInTableView:(NSTableView *)aTableView; {
    return [voiceList count];
}

- (id)tableView:(NSTableView *)aTableView objectValueForTableColumn:(NSTableColumn *)aTableColumn row:(int)rowIndex; {
    NSDictionary *dict = [NSSpeechSynthesizer attributesForVoice:[voiceList objectAtIndex:rowIndex]];
    return [dict objectForKey:NSVoiceName];
}

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
    int row = [tableView selectedRow];
    if (row == -1) {
        return;
    }
    
    NSString *selectedVoice = [voiceList objectAtIndex:row];
    [speechSynth setVoice:selectedVoice];
    NSLog(@"new voice = %@", selectedVoice);
}
@end
