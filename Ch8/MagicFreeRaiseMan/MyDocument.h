//
//  MyDocument.h
//  MagicFreeRaiseMan
//
//  Created by Sam Krishna on 8/7/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//


#import <Cocoa/Cocoa.h>
@class Person;

@interface MyDocument : NSDocument
{
    NSMutableArray *employees;
    IBOutlet NSTableView *tableView;
}

- (IBAction)createEmployee:(id)sender;
- (IBAction)deleteSelectedEmployees:(id)sender;

@end
