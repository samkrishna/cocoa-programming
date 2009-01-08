/*
 *  prog11_5.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define YES 1
#define NO 0

int is_within(char *string, char c);

int main (int argc, const char * argv[]) {
    char *string = "The lazy fox loves to have sex.";
    int result = is_within(string, 'q');
    
    if (result) {
        printf("The character was found.\n");
    } else {
        printf("The character was not found.\n");
    }
   
    return 0;
}

int is_within(char *string, char c) {
    char *ch = string;
    
    while (*ch != c) {
        ch++;
        
        if (*ch == '\0') return NO;
    }
    
    return YES;
}