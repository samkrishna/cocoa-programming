#import <Foundation/Foundation.h>
#import "LotteryEntry.h"

int main (int argc, const char * argv[]) {
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    NSMutableArray *array = [[NSMutableArray alloc] init];
    // NSLog(@"First item = %@", [array objectAtIndex:0]);
    int i;
    NSCalendarDate *now = [[NSCalendarDate alloc] init]; // Create the date object
    srandom(time(NULL));    // Seed the random # generator
    
    // insert code here...
    for (i = 0; i < 10; i++) {
        // Create a calendar date object i weeks from now
        NSCalendarDate *iWeeksFromNow = [now dateByAddingYears:0
                                                        months:0
                                                          days:(i * 7)
                                                         hours:0
                                                       minutes:0
                                                       seconds:0];
        
        
        // Create a new instance of LotteryEntry
        LotteryEntry *newEntry = [[LotteryEntry alloc] initWithEntryDate:iWeeksFromNow];
        [array addObject:newEntry];
        [newEntry release];
    }
    
    [now release];
    now = nil;
    
    for (LotteryEntry *entryToPrint in array) {
        // Display its contents
        NSLog(@"%@", entryToPrint);
    }

    [array release];
    array = nil;
    [pool drain];
    NSLog(@"GC = %@", [NSGarbageCollector defaultCollector]);
    
    return 0;
}
