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

- (id)initWithEntryDate:(NSCalendarDate *)theDate; {
    if (![super init]) return nil;

    NSAssert(theDate != nil, @"Argument must be non-nil!");
    firstNumber = random() % 100 + 1;
    secondNumber = random() % 100 + 1;
    entryDate = theDate;
    
    return self;
}

// Blah Blah Blah

- (void)setEntryDate:(NSCalendarDate *)theDate; {
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
    return [NSString stringWithFormat:@"%@ = %d and %d", 
            [entryDate descriptionWithCalendarFormat:@"%B %d %Y"], firstNumber, secondNumber];
}
@end
