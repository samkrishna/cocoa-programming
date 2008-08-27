//
//  Department.h
//  Departments
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <CoreData/CoreData.h>

@class Employee;

@interface Department :  NSManagedObject  
{
}

@property (retain) NSString * deptName;
@property (retain) NSSet* employees;
@property (retain) Employee * manager;

@end

@interface Department (CoreDataGeneratedAccessors)
- (void)addEmployeesObject:(Employee *)value;
- (void)removeEmployeesObject:(Employee *)value;

@end

