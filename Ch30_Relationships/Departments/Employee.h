//
//  Employee.h
//  Departments
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <CoreData/CoreData.h>
@class Department;

@interface Employee :  NSManagedObject  
{
}

@property (retain) NSString * lastName;
@property (retain) NSString * firstName;
@property (retain) Department * department;

- (NSString *)fullName;


@end


