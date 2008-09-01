//
//  Person.m
//  RaiseMan
//
//  Created by Sam Krishna on 8/7/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "Person.h"


@implementation Person

- (id)init
{
    [super init];
    expectedRaise = 5.0;
    personName = @"New Person";
    return self;
}

- (void)dealloc
{
    [personName release];
    [super dealloc];
}

- (void)setNilValueForKey:(NSString *)key
{
    if ([key isEqual:@"expectedRaise"]) {
        [self setExpectedRaise:0.0];
    } else {
        [super setNilValueForKey:key];
    }
}

@synthesize personName;
@synthesize expectedRaise;

@end
