//
//  MyDocument.h
//  OvalFun
//
//  Created by Sam Krishna on 8/22/08.
//  Copyright __MyCompanyName__ 2008 . All rights reserved.
//


#import <Cocoa/Cocoa.h>
@class OvalView;

@interface MyDocument : NSDocument
{
    IBOutlet OvalView *ovalView;
    NSMutableArray *ovals;
    NSBezierPath *path;
}

@property (retain) NSArray *ovals;
@property (retain) NSBezierPath *path;

- (void)addMyOval:(NSBezierPath *)oval;

// Undo Methods
- (void)insertObject:(NSBezierPath *)o inOvalsAtIndex:(int)index;
- (void)removeObjectFromOvalsAtIndex:(int)index;

- (NSArray *)attributeKeys;
- (NSDictionary *)dictionaryWithValuesForKeys:(NSArray *)keys;

@end
