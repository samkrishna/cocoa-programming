#import <Cocoa/Cocoa.h>

@interface AppController : NSObject {
    IBOutlet id tableView;
    IBOutlet id textField;
    
    NSMutableArray *toDoList;
}

- (IBAction)createNewItem:(id)sender;

@end
