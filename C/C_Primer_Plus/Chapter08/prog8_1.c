/*
 *  prog8_1.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int charCount = 0;
    char ch;
    
    printf("Enter input and then signal by using EOF (CTRL-Z):\n");
    
    while ((ch = getchar()) != EOF) {
        charCount++;
    }
    
    printf("\n\nThe total number of characters entered is %i.\n", charCount);
    
    return 0;
}

