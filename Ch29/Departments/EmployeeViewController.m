//
//  EmployeeViewController.m
//  Departments
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "EmployeeViewController.h"


@implementation EmployeeViewController

- (id)init
{
    if (![super initWithNibName:@"EmployeeView"
                         bundle:nil]) {
        return nil;
    }
    [self setTitle:@"Employees"];
    return self;
}

@end
