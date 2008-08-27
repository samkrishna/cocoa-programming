//
//  AppController.h
//  TypingTutor
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class BigLetterView;

@interface AppController : NSObject
{
    // Outlets
    IBOutlet BigLetterView *inLetterView;
    IBOutlet BigLetterView *outLetterView;
    
    // Data
    NSArray *letters;
    int lastIndex;
    
    // Time
    NSTimer *timer;
    int count;
}

- (IBAction)stopGo:(id)sender;
- (void)incrementCount;
- (void)resetCount;
- (void)showAnotherLetter;

@end
