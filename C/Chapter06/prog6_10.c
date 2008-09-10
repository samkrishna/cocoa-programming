/*
 *  prog6_10.c
 *  Chapter6
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    char c;
    char string[100]; // seems like a trick of sorts. I almost wonder if the Q has an idea that could make both malloc() and a hard array unneccessary. <sigh>
    int i = 0;
    
    while (scanf("%c", &c) && c != '\n') {
        string[i++] = c;
    }
    
    printf("reverse string is: ");
    while (i >= 0) {
        printf("%c", string[i--]);
    }
    
    return 0;
}

