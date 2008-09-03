#import <Foundation/Foundation.h>


int main (int argc, const char * argv[]) 
{
    NSAutoreleasePool 	*pool = [[NSAutoreleasePool alloc] init];
    NSMutableArray 		*resultArray = [NSMutableArray array];
    NSString	  			*testString = @"{Bush, George, W.},{Clinton, William, J.}";
    NSCharacterSet 		*nameCharacterSet = [NSCharacterSet alphanumericCharacterSet];
    NSScanner	  			*nameScanner;
    
    // Initialize a scanner with the string to scan
    nameScanner = [[NSScanner alloc] initWithString:testString];
    
    while(![nameScanner isAtEnd])
    {
        // Skip characters that can not be in a name and
        // discard the sub-string that does not include a name 
        [nameScanner scanUpToCharactersFromSet:nameCharacterSet intoString:nil];
        
        // if there are any characters left they must be part of a name
        if(![nameScanner isAtEnd])
        {
            NSString	    *foundName; // this variable will hold pointer
            // to autoreleased string created
            // by the scanner
            [nameScanner scanCharactersFromSet:nameCharacterSet intoString:&foundName];
            
            // Store the name in an array
            [resultArray addObject:foundName];
        }
    }
    
    [nameScanner release];
    
    // Output the description of resultArray
    NSLog(@"%@", [resultArray description]);
    
    [pool release];
    return 0;
}
