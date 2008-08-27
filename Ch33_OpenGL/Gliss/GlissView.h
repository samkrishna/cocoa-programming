//
//  GlissView.h
//  Gliss
//
//  Created by Sam Krishna on 8/26/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface GlissView : NSOpenGLView
{
    IBOutlet NSMatrix *sliderMatrix;
    float lightX, theta, radius;
    int displayList;
}
- (IBAction)changeParameter:(id)sender;
@end