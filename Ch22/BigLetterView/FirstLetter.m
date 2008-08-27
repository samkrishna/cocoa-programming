//
//  FirstLetter.m
//  BigLetterView
//
//  Created by Sam Krishna on 8/24/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "FirstLetter.h"


@implementation NSString (FirstLetter)

- (NSString *)BNR_firstLetter
{
    if ([self length] < 2) {
        return self;
    }
    NSRange r;
    r.location = 0;
    r.length = 1;
    return [self substringWithRange:r];
}

@end