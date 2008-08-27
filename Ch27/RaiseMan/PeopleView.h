//
//  PeopleView.h
//  RaiseMan
//
//  Created by Sam Krishna on 8/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface PeopleView : NSView {
    NSArray *people;
    NSMutableDictionary *attributes;
    float lineHeight;
    NSRect pageRect;
    int linesPerPage;
    int currentPage;
    
}
- (id)initWithPeople:(NSArray *)array;
@end