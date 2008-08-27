//
//  AppController.m
//  iPing
//
//  Created by Sam Krishna on 8/26/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "AppController.h"


@implementation AppController

- (IBAction)startStopPing:(id)sender
{
    // Is the task running?
    if (task) {
        [task interrupt];
    } else {
        task = [[NSTask alloc] init];
        [task setLaunchPath:@"/sbin/ping"];
        NSArray *args = [NSArray arrayWithObjects:@"-c10", [hostField stringValue], nil];
        [task setArguments:args];
        
        // Release the old pipe
        [pipe release];
        // Create a new pipe
        pipe = [[NSPipe alloc] init];
        [task setStandardOutput:pipe];
        
        NSFileHandle *fh = [pipe fileHandleForReading];
        
        NSNotificationCenter *nc;
        nc = [NSNotificationCenter defaultCenter];
        [nc removeObserver:self];
        [nc addObserver:self
               selector:@selector(dataReady:)
                   name:NSFileHandleReadCompletionNotification
                 object:fh];
        [nc addObserver:self
               selector:@selector(taskTerminated:)
                   name:NSTaskDidTerminateNotification
                 object:task];
        [task launch];
        [outputView setString:@""];
        
        [fh readInBackgroundAndNotify];
    }
}

- (void)appendData:(NSData *)d
{
    NSString *s = [[NSString alloc] initWithData:d
                                        encoding:NSUTF8StringEncoding];
    NSTextStorage *ts = [outputView textStorage];
    [ts replaceCharactersInRange:NSMakeRange([ts length], 0)
                      withString:s];
    [s release];
}

- (void)dataReady:(NSNotification *)n
{
    NSData *d;
    d = [[n userInfo] valueForKey:NSFileHandleNotificationDataItem];
    
    NSLog(@"dataReady:%d bytes", [d length]);
    
    if ([d length]) {
        [self appendData:d];
    }
    
    // If the task is running, start reading again
    if (task)
        [[pipe fileHandleForReading] readInBackgroundAndNotify];
}

- (void)taskTerminated:(NSNotification *)note
{
    NSLog(@"taskTerminated:");
    
    [task release];
    task = nil;
    
    [startButton setState:0];
    
}

@end
