//
//  MyDocument.m
//  RaiseMan
//
//  Created by Sam Krishna on 8/7/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//

#import "MyDocument.h"
#import "Person.h"

@implementation MyDocument

- (id)init
{
    self = [super init];
    if (self) {
        // Add your subclass-specific initialization here.
        // If an error occurs here, send a [self release] message and return nil.
        employees = [[NSMutableArray alloc] init];    
    }
    return self;
}

- (void)dealloc {
    [self setEmployees:nil];
    [super dealloc];
}


#pragma mark -
#pragma mark Action methods

- (IBAction)createEmployee:(id)sender
{
    NSWindow *w = [tableView window];
    
    // Try to end any editing that is taking place
    BOOL editingEnded = [w makeFirstResponder:w];
    if (!editingEnded) {
        NSLog(@"Unable to end editing");
        return;
    }
    NSUndoManager *undo = [self undoManager];
    
    // Has an edit occurred already in this event?
    if ([undo groupingLevel]) {
        // Close the last group
        [undo endUndoGrouping];
        // Open a new group
        [undo beginUndoGrouping];
    }
    // Create the object
    Person *p = [employeeController newObject];
    
    // Add it to the content array of 'employeeController'
    [employeeController addObject:p];
    [p release];
    // Re-sort (in case the user has sorted a column)
    [employeeController rearrangeObjects];
    
    // Get the sorted array
    NSArray *a = [employeeController arrangedObjects];
    
    // Find the object just added
    int row = [a indexOfObjectIdenticalTo:p];
    NSLog(@"starting edit of %@ in row %d", p, row);
    
    // Begin the edit in the first column
    [tableView editColumn:0
                      row:row
                withEvent:nil
                   select:YES];
}

#pragma mark -
#pragma mark Accessors - 'employees'

- (void)setEmployees:(NSMutableArray *)a
{
    if (a == employees)
        return;
    
    for (Person *person in employees) {
        [self stopObservingPerson:person];
    }
    
    [a retain];
    [employees release];
    employees = a;
    for (Person *person in employees) {
        [self startObservingPerson:person];
    }
}


- (void)insertObject:(Person *)p inEmployeesAtIndex:(int)index
{
    NSLog(@"adding %@ to %@", p, employees);
    // Add the inverse of this operation to the undo stack
    NSUndoManager *undo = [self undoManager];
    [[undo prepareWithInvocationTarget:self]
     removeObjectFromEmployeesAtIndex:index];
    if (![undo isUndoing]) {
        [undo setActionName:@"Insert Person"];
    }

    // Add the Person to the array
    [self startObservingPerson:p];
    [employees insertObject:p atIndex:index];
}

- (void)removeObjectFromEmployeesAtIndex:(int)index
{
    Person *p = [employees objectAtIndex:index];
    NSLog(@"removing %@ from %@", p, employees);
    // Add the inverse of this operation to the undo stack
    NSUndoManager *undo = [self undoManager];
    [[undo prepareWithInvocationTarget:self] insertObject:p
                                       inEmployeesAtIndex:index];
    if (![undo isUndoing]) {
        [undo setActionName:@"Delete Person"];
    }
    
    // Delete the Person to the array
    [self stopObservingPerson:p];
    [employees removeObjectAtIndex:index];
}

- (void)startObservingPerson:(Person *)person
{
    [person addObserver:self
             forKeyPath:@"personName"
                options:NSKeyValueObservingOptionOld
                context:NULL];
    
    [person addObserver:self
             forKeyPath:@"expectedRaise"
                options:NSKeyValueObservingOptionOld
                context:NULL];
}

- (void)stopObservingPerson:(Person *)person
{
    [person removeObserver:self forKeyPath:@"personName"];
    [person removeObserver:self forKeyPath:@"expectedRaise"];
}

- (void)changeKeyPath:(NSString *)keyPath
             ofObject:(id)obj
              toValue:(id)newValue
{
    // setValue:forKeyPath: will cause the key-value observing method
    // to be called, which takes care of the undo stuff
    [obj setValue:newValue forKeyPath:keyPath];
}

- (void)observeValueForKeyPath:(NSString *)keyPath
                      ofObject:(id)object
                        change:(NSDictionary *)change
                       context:(void *)context
{
    NSUndoManager *undo = [self undoManager];
    id oldValue = [change objectForKey:NSKeyValueChangeOldKey];
    
    // NSNull objects are used to represent nil in a dictionary
    if (oldValue == [NSNull null]) {
        oldValue = nil;
    }
    NSLog(@"oldValue = %@", oldValue);
    [[undo prepareWithInvocationTarget:self] changeKeyPath:keyPath
                                                  ofObject:object
                                                   toValue:oldValue];
    [undo setActionName:@"Edit"];
}

#pragma mark -
#pragma mark NSDocument methods

- (NSString *)windowNibName
{
    // Override returning the nib file name of the document
    // If you need to use a subclass of NSWindowController or if your document supports multiple NSWindowControllers, you should remove this method and override -makeWindowControllers instead.
    return @"MyDocument";
}

- (void)presentError:(NSError *)error modalForWindow:(NSWindow *)window delegate:(id)delegate didPresentSelector:(SEL)didPresentSelector contextInfo:(void *)contextInfo
{
	NSDictionary *ui = [error userInfo];
	NSError *underlying = [ui objectForKey:NSUnderlyingErrorKey];
	
	NSLog(@"error = %@, userInfo = %@, underlying info = %@", error, ui, [underlying userInfo]);
	[super presentError:error 
		 modalForWindow:window 
			   delegate:delegate 
	 didPresentSelector:didPresentSelector 
			contextInfo:contextInfo];
}

- (void)windowControllerDidLoadNib:(NSWindowController *) aController
{
    [super windowControllerDidLoadNib:aController];
    // Add any code here that needs to be executed once the windowController has loaded the document's window.
}

- (NSData *)dataOfType:(NSString *)typeName
                 error:(NSError **)outError
{
    // End editing
    [[tableView window] endEditingFor:nil];
    
    // Create an NSData object from the employees array
    return [NSKeyedArchiver archivedDataWithRootObject:employees];
}

- (BOOL)readFromData:(NSData *)data ofType:(NSString *)typeName error:(NSError **)outError
{
    NSLog(@"About to read data of type %@", typeName);
    NSMutableArray *newArray = nil;
    @try {
        newArray = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    }
    @catch (NSException *e) {
        if (outError) {
            NSDictionary *d = [NSDictionary
                               dictionaryWithObject:@"The data is corrupted."
                               forKey:NSLocalizedFailureReasonErrorKey];
            *outError = [NSError errorWithDomain:NSOSStatusErrorDomain
                                            code:unimpErr
                                        userInfo:d];
        }
        return NO;
    }
    [self setEmployees:newArray];
    return YES;
}


@end
