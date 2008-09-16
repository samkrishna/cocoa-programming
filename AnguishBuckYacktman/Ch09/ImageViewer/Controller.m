//
//  Controller.m
//  ImageViewer
//
//  Created by Sam Krishna on 9/1/08.
//  Copyright 2008 Chaordium Software. All rights reserved.
//

#import "Controller.h"


@implementation Controller

@synthesize photo;

- (id)init
{
    [super init];
    
    photo = [[NSData alloc] init];
    
    return self;
}

- (void)dealloc
{
    [photo release];
    [super dealloc];
}

@end
