//
//  DepartmentViewController.m
//  Departments
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "DepartmentViewController.h"


@implementation DepartmentViewController

- (id)init
{
    if (![super initWithNibName:@"DepartmentView"
                         bundle:nil]) {
        return nil;
    }
    [self setTitle:@"Departments"];
    return self;
}

@end
