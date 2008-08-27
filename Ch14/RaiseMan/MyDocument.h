//
//  MyDocument.h
//  RaiseMan
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
    IBOutlet NSArrayController *employeeController;
}

- (IBAction)createEmployee:(id)sender;

- (void)setEmployees:(NSMutableArray *)a;
- (void)removeObjectFromEmployeesAtIndex:(int)index;
- (void)insertObject:(Person *)p inEmployeesAtIndex:(int)index;

- (void)stopObservingPerson:(Person *)person;
- (void)startObservingPerson:(Person *)person;
- (void)handleColorChange:(NSNotification *)note;

@end
