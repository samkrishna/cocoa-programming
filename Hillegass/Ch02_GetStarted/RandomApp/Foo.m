//
//  Foo.m
//  RandomApp
//
//  Created by Sam Krishna on 5/7/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "Foo.h"


@implementation Foo

- (IBAction)seed:(id)sender; {
    // Seed the random number generator with time
    srandom(time(NULL));
    [textField setStringValue:@"Generator Seeded"];
}

- (IBAction)generate:(id)sender; {
    int generated;
    
    generated = (random() % 100) + 1;
    NSLog(@"generated = %d", generated);
    
    [textField setIntValue:generated];
}

- (void)awakeFromNib {
    NSCalendarDate *now = [NSCalendarDate calendarDate];
    [textField setObjectValue:now];
}

@end
