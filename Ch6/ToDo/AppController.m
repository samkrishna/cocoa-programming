#import "AppController.h"

@implementation AppController

- (void)awakeFromNib {
    [tableView setDataSource:self];
}

- (id)init {
    [super init];
    toDoList = [[NSMutableArray array] retain];
    return self;
}

- (void)dealloc {
    [toDoList release];
    
    [super dealloc];
}

- (IBAction)createNewItem:(id)sender {
    [toDoList addObject:[textField stringValue]];
    [tableView reloadData];
}

- (NSInteger)numberOfRowsInTableView:(NSTableView *)aTableView {
    return [toDoList count];
}

- (id)tableView:(NSTableView *)aTableView objectValueForTableColumn:(NSTableColumn *)aTableColumn row:(NSInteger)rowIndex {
    return [toDoList objectAtIndex:rowIndex];
}

@end
