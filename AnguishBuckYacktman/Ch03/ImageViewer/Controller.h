//
//  Controller.h
//  ImageViewer
//
//  Created by Sam Krishna on 9/1/08.
//  Copyright 2008 Chaordium Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface Controller : NSObject {
    NSData *photo;
}

@property (readwrite, assign) NSData *photo;

@end
