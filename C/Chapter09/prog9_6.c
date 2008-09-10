/*
 *  prog9_6.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int location(char ch);

int main (int argc, const char * argv[]) {
    char ch;
    
    while ((ch = getchar()) != EOF) {
        if (ch >= 'A' && ch <= 'z') {
            printf("%c is located at position %d in the alphabet.\n", ch, location(ch));            
        }
    }
    
    return 0;
}

int location(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 64;
    }
    
    if (ch >= 'a' && ch <= 'z') {
        return ch - 96;
    }
    
    return -1;
}
