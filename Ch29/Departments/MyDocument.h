//
//  MyDocument.h
//  Departments
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class ManagingViewController;

@interface MyDocument : NSPersistentDocument {
    IBOutlet NSBox *box;
    IBOutlet NSPopUpButton *popUp;
    NSMutableArray *viewControllers;
}
- (IBAction)changeViewController:(id)sender;
- (void)displayViewController:(ManagingViewController *)vc;

@end