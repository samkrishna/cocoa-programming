//
//  MyDocument.m
//  OvalFun
//
//  Created by Sam Krishna on 8/22/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//

#import "MyDocument.h"

@implementation MyDocument

- (id)init
{
    self = [super init];
    if (self) {
        
        // Add your subclass-specific initialization here.
        // If an error occurs here, send a [self release] message and return nil.
        
    }
    return self;
}

- (NSString *)windowNibName
{
    // Override returning the nib file name of the document
    // If you need to use a subclass of NSWindowController or if your document supports multiple NSWindowControllers, you should remove this method and override -makeWindowControllers instead.
    return @"MyDocument";
}

- (void)windowControllerDidLoadNib:(NSWindowController *) aController
{
    [super windowControllerDidLoadNib:aController];
    // Add any code here that needs to be executed once the windowController has loaded the document's window.
}

- (NSData *)dataOfType:(NSString *)typeName error:(NSError **)outError
{
    return [NSKeyedArchiver archivedDataWithRootObject:ovalView];
}

- (BOOL)readFromData:(NSData *)data ofType:(NSString *)typeName error:(NSError **)outError
{
    OvalView *newView = nil;
    @try {
        newView = [NSKeyedUnarchiver unarchiveObjectWithData:data];
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
    ovalView = newView;
	return YES;
}

@end
