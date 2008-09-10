/*
 *  prog4_1.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int spaceCount = 0;
    int newlineCount = 0;
    int charCount = 0;
    char c;
    
    printf("Enter text and press \'#\' to halt.\n");
    
    while (scanf("%c", &c) && c != '#') {
        if (c != ' ' && c != '\n') {
            charCount++;
            continue;
        }
        
        if (c == '\n') {
            newlineCount++;
        }
        
        if (c == ' ') {
            spaceCount++;
        }
    }
    
    printf("spaceCount = %i\n", spaceCount);
    printf("newlineCount = %i\n", newlineCount);
    printf("charCount = %i\n", charCount);

    return 0;
}

