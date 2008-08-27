//
//  MyDocument.h
//  ZIPspector
//
//  Created by Sam Krishna on 8/26/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//


#import <Cocoa/Cocoa.h>

@interface MyDocument : NSDocument
{
    IBOutlet NSTableView *tableView;
    NSArray *filenames;
}
@end
