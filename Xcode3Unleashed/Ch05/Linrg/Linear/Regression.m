//
//  Regression.m
//  Linear
//
//  Created by Sam Krishna on 9/16/08.
//  Copyright 2008 Chaordium Software. All rights reserved.
//

#import "Regression.h"
#import "DataPoint.h"

@implementation Regression

@synthesize slope;
@synthesize intercept;
@synthesize correlation;
@synthesize dataPoints;

+ (void) initialize
{
    // Let Key-Value Observing know that every time
    // dataPoints changes, canCompute may change.
    [self setKeys: [NSArray arrayWithObject: @"dataPoints"] triggerChangeNotificationsForDependentKey: @"canCompute"];
}

- (id)init
{
    if (![super init]) {
        return nil;
    }
    
    dataPoints = [[NSMutableArray alloc] init];
    return self;
}

- (void)dealloc
{
    [dataPoints release];
    [super dealloc];
}

- (BOOL) canCompute
{
    return [dataPoints count] > 1;
}

- (void) computeWithLinrg
{
    if (![self canCompute]) {
        // Regression not possible; zero out and give up.
        [self setSlope: 0.0];
        [self setIntercept: 0.0];
        [self setCorrelation: 0.0];
        return;
    }
    
    // With the Linrg tool...
    NSBundle *myBundle = [NSBundle mainBundle];
    NSString *linrgPath = [myBundle pathForResource: @"Linrg" ofType: @""];
    linrgTask = [[NSTask alloc] init];
    [linrgTask setLaunchPath: linrgPath];
    
    // ...hook into stdin...
    NSPipe *inputPipe = [[NSPipe alloc] init];
    NSFileHandle *inputForData = [inputPipe fileHandleForWriting];
    [linrgTask setStandardInput: inputPipe];
    [inputPipe release];
    
    //   ...hook into stdout...
    NSPipe *outputPipe = [[NSPipe alloc] init];
    NSFileHandle *outputForResults = [outputPipe fileHandleForReading];
    [linrgTask setStandardOutput: outputPipe];
    [outputPipe release];
    
    // ...await   output   in  the  dataRead: method...
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(dataRead:)
                                                 name:NSFileHandleReadToEndOfFileCompletionNotification
                                               object:outputForResults];
    [outputForResults readToEndOfFileInBackgroundAndNotify];
    
    // ...and run Linrg.
    [linrgTask launch];
    
    // For each DataPoint...
    NSEnumerator *iter = [dataPoints objectEnumerator];
    DataPoint *curr;
    while (curr = [iter nextObject]) {
        NSString *currAsString;
        // ... format point as string...
        currAsString = [NSString stringWithFormat: @"%g %g\n", [curr x], [curr y]];
        
        // ... reduce string to ASCII data...
        NSData *currAsData = [currAsString dataUsingEncoding:NSASCIIStringEncoding];
        // ... put data into stdin...
        [inputForData writeData: currAsData];
    }
    
    // ... then terminate stdin.
    [inputForData closeFile];
}

- (void)dataRead:(NSNotification *)aNotice
{
    // When data arrives on stdout...
    NSDictionary *info = [aNotice userInfo];
    NSData *theData = [info objectForKey:NSFileHandleNotificationDataItem];
    
    // ...convert the data to a string...
    NSString *stringResult = [[NSString alloc] initWithData:theData encoding:NSASCIIStringEncoding];
    NSScanner *scanner = [NSScanner scannerWithString:stringResult];
    double scratch;
    
    // ...and step through, collecting slope...
    [scanner scanDouble: &scratch];
    [self setSlope: scratch];
    
    // ... intercept...
    [scanner scanDouble: &scratch];
    [self setIntercept: scratch];
    
    // ...and correlation,
    [scanner scanDouble: &scratch];
    [self setCorrelation: scratch];
    [stringResult release];
    
    // Done with Linrg.
    [linrgTask release];
    linrgTask = nil;
}

#pragma mark NSCoding

- (void)encodeWithCoder: (NSCoder *) coder
{
    [coder encodeObject:dataPoints forKey:@"dataPoints"];
    [coder encodeDouble:slope forKey:@"slope"];
    [coder encodeDouble:intercept forKey:@"intercept"];
    [coder encodeDouble:correlation forKey:@"correlation"];
}

- (id)initWithCoder: (NSCoder *) coder
{
    [self setDataPoints:[coder decodeObjectForKey:@"dataPoints"]];
    [self setSlope:[coder decodeDoubleForKey: @"slope"]];
    [self setIntercept:[coder decodeDoubleForKey:@"intercept"]];
    [self setCorrelation:[coder decodeDoubleForKey: @"correlation"]];
    return self;
}

@end
