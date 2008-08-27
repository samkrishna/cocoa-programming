//
//  AppController.h
//  ImageFun
//
//  Created by Sam Krishna on 8/21/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class StretchView;

@interface AppController : NSObject {
    IBOutlet StretchView *stretchView;
}

- (IBAction)showOpenPanel:(id)sender;

@end
