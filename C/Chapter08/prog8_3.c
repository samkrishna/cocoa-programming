/*
 *  prog8_3.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int upperCount = 0;
    int lowerCount = 0;
    char ch;
    
    printf("Enter upper and lower-case text. Use CTRL-D to end input.\n");
    
    while ((ch = getchar()) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            upperCount++;
        }
        
        if (ch >= 'a' && ch <= 'z') {
            lowerCount++;
        }
    }
    
    printf("\n# uppercase: %d\n", upperCount);
    printf("# lowercase: %d\n", lowerCount);
    
    return 0;
}

