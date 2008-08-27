// 
//  Employee.m
//  Departments
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "Employee.h"
#import "Department.h"

@implementation Employee 

@dynamic lastName;
@dynamic firstName;
@dynamic department;

+ (NSSet *)keyPathsForValuesAffectingFullName
{
    return [NSSet setWithObjects:@"firstName", @"lastName", nil];
}

- (NSString *)fullName
{
    NSString *first = [self firstName];
    NSString *last = [self lastName];
    if (!first)
        return last;
    
    if (!last)
        return first;
    
    return [NSString stringWithFormat:@"%@ %@", first, last];
}

@end
