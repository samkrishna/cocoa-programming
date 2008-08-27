//
//  CarArrayController.m
//  CarLot
//
//  Created by Sam Krishna on 8/21/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "CarArrayController.h"


@implementation CarArrayController

- (id)newObject
{
    id newObj = [super newObject];
    NSDate *now = [NSDate date];
    [newObj setValue:now forKey:@"datePurchased"];
    return newObj;
}

@end
