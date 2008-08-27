//
//  MyDocument.m
//  OvalFun
//
//  Created by Sam Krishna on 8/22/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//

#import "MyDocument.h"
#import "OvalView.h"

@implementation MyDocument

@synthesize ovals;
@synthesize path;

- (id)init
{
    self = [super init];
    if (self) {
        ovals = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void)dealloc {
    [ovals release];
    [path release];
    [super dealloc];
}

- (NSString *)windowNibName
{
    return @"MyDocument";
}

- (void)windowControllerDidLoadNib:(NSWindowController *) aController
{
    [super windowControllerDidLoadNib:aController];
    // Add any code here that needs to be executed once the windowController has loaded the document's window.

    if (path) {
        NSLog(@"About to set the ovalView\'s path!");
        [ovalView setPath:path];        
    } else {
        NSLog(@"About to set MyDocument\'s path!");
        [self setPath:[ovalView path]];
    }
}

- (NSData *)dataOfType:(NSString *)typeName error:(NSError **)outError
{
    // End editing
    [[ovalView window] endEditingFor:nil];
    
    // Create an NSData object from the object model
    return [NSKeyedArchiver archivedDataWithRootObject:[self dictionaryWithValuesForKeys:[self attributeKeys]]];
}

- (BOOL)readFromData:(NSData *)data ofType:(NSString *)typeName error:(NSError **)outError
{
    NSDictionary *newDictionary = nil;
    
    @try {
        newDictionary = [NSKeyedUnarchiver unarchiveObjectWithData:data];
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
    
    [self setValuesForKeysWithDictionary:newDictionary];
	return YES;
}

- (void)addMyOval:(NSBezierPath *)oval; {
    [self insertObject:oval inOvalsAtIndex:[ovals count]];
}

#pragma mark Undo

- (void)insertObject:(NSBezierPath *)o inOvalsAtIndex:(int)index
{
    NSUndoManager *undo = [self undoManager];
    [[undo prepareWithInvocationTarget:self] removeObjectFromOvalsAtIndex:index];
    if (![undo isUndoing]) {
        [undo setActionName:@"Insert Oval"];
    }

    [ovals insertObject:o atIndex:index];
    [ovalView setNeedsDisplay:YES];
}

- (void)removeObjectFromOvalsAtIndex:(int)index
{
    NSBezierPath *o = [ovals objectAtIndex:index];
    NSUndoManager *undo = [self undoManager];
    [[undo prepareWithInvocationTarget:self] insertObject:o inOvalsAtIndex:index];
    if (![undo isUndoing]) {
        [undo setActionName:@"Delete Oval"];
    }
    
    [ovals removeObjectAtIndex:index];
    [ovalView setNeedsDisplay:YES];
}

#pragma mark Object Model-as-Dictionary

- (NSArray *)attributeKeys {
    return [NSArray arrayWithObjects:
        @"ovals",
        @"path",
        nil];
}

- (NSDictionary *)dictionaryWithValuesForKeys:(NSArray *)keys; {
    return [self valuesForKeys:[self attributeKeys]];
}

@end
