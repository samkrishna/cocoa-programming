/*
 *  prog7_6.c
 *  Chapter7
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    char previous = '\0';
    char current = '\0';
    int eiCount = 0;
    
    printf("Enter line input and use \'#\' to terminate. We'll count the # of \'ei\'s in the input.\n\n");
    
    while ((current = getchar()) != '#') {
        if (current == 'i') {
            if (previous == 'e') {
                eiCount++;
            }
        }
        
        previous = current;
    }
    
    printf("\n\nThe # of \'ei\'s in the input is %i.\n", eiCount);
    
    return 0;
}

