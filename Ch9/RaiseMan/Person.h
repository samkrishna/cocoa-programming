//
//  Person.h
//  RaiseMan
//
//  Created by Sam Krishna on 8/7/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface Person : NSObject {
    NSString *personName;
    float expectedRaise;
}

@property (readwrite, copy) NSString *personName;
@property (readwrite) float expectedRaise;

@end
