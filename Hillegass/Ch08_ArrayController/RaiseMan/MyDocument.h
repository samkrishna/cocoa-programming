//
//  MyDocument.h
//  RaiseMan
//
//  Created by Sam Krishna on 8/7/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//


#import <Cocoa/Cocoa.h>

@interface MyDocument : NSDocument
{
    NSMutableArray *employees;
}

- (void)setEmployees:(NSMutableArray *)a;

@end
