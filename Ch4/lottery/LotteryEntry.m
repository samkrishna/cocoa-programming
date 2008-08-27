//
//  LotteryEntry.m
//  lottery
//
//  Created by Sam Krishna on 5/7/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "LotteryEntry.h"


@implementation LotteryEntry

- (id)init {
    return [self initWithEntryDate:[NSCalendarDate calendarDate]];
}

- (void)dealloc {
    NSLog(@"deallocating %@", self);
    [entryDate release];
    [super dealloc];
}

- (id)initWithEntryDate:(NSCalendarDate *)theDate; {
    if (![super init]) return nil;

    NSAssert(theDate != nil, @"Argument must be non-nil!");

    entryDate = [theDate retain];
    firstNumber = random() % 100 + 1;
    secondNumber = random() % 100 + 1;
    
    return self;
}

- (void)setEntryDate:(NSCalendarDate *)theDate; {
    [theDate retain];
    [entryDate release];
    entryDate = theDate;
}

- (NSCalendarDate *)entryDate; {
    return entryDate;
}

- (int)firstNumber; {
    return firstNumber;
}

- (int)secondNumber; {
    return secondNumber;
}

- (NSString *)description {
    // The shiny autoreleased way
    return [NSString stringWithFormat:@"%@ = %d and %d",
            [entryDate descriptionWithCalendarFormat:@"%B %d %Y"], firstNumber, secondNumber];
    
    // The tedious, demonstrative autoreleased way
    //return [[[NSString alloc] initWithFormat:@"%@ = %d and %d", 
    //        [entryDate descriptionWithCalendarFormat:@"%B %d %Y"], firstNumber, secondNumber] autorelease];
}
@end
