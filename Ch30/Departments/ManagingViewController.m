//
//  ManagingViewController.m
//  Departments
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "ManagingViewController.h"

@implementation ManagingViewController
@synthesize managedObjectContext;

- (void)dealloc
{
    [managedObjectContext release];
    [super dealloc];
}
@end