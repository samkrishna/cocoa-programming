/*
 *  prog11_4.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

char *findChar(char *string, char character);

int main (int argc, const char * argv[]) {
    char *string = "The lazy fox loves to have sex.";
    char *ch = findChar(string, 'q');
    
    if (*ch != '\0') {
        printf("The found character is %c.\n", *ch);
    } else {
        printf("The character was not found.\n");
    }
    
    return 0;
}

char *findChar(char *string, char character) {
    char *ch = string;
    
    while (*ch != character) {
        ch++;
        
        if (*ch == '\0') return ch;
    }
    
    return ch;
}
