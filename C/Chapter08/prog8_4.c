/*
 *  prog8_4.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int spaceCount = 0;
    int charCount = 0;
    char ch;
    
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            spaceCount++;
        } else {
            charCount++;
        }
    }
    
    printf("The avg number of letters per word is %i.\n", charCount / (spaceCount + 1));
    
    return 0;
}

