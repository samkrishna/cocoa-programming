/*
 *  prog4_4.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int subCount = 0;
    char c;
    
    printf("Enter input (use \'#\' to terminate):\n");
    
    while (scanf("%c", &c) && c != '#') {
        if (c == '.') {
            printf("!");
            subCount++;
        } else if (c == '!') {
            printf("!!");
            subCount++;
        } else {
            printf("%c", c);
        }
    }
    
    printf("\n\nThe total number of substitutions is %i.\n", subCount);
    
    return 0;
}

