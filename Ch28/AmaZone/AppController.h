//
//  AppController.h
//  AmaZone
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

@interface AppController : NSObject
{
    IBOutlet NSProgressIndicator *progress;
    IBOutlet NSTextField *searchField;
    IBOutlet NSTableView *tableView;
    IBOutlet NSWindow *webSheet;
    IBOutlet WebView *webView;
    NSXMLDocument *doc;
    NSArray *itemNodes;
}

- (IBAction)fetchBooks:(id)sender;
- (IBAction)closeWebSheet:(id)sender;
- (NSString *)stringForPath:(NSString *)xp ofNode:(NSXMLNode *)n;

@end