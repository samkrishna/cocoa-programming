/*
 *  prog6_7.c
 *  Chapter6
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int array[8];
    int i = 0;
    
    printf("Enter 8 integers: ");
    while (scanf("%i", &array[i++])) {
        if (i == 8) break;
    }
    
    printf("The array, in reverse order is: ");
    for (i = 7; i > 0; i--) {
        printf("%i ", array[i]);
    }
    printf("\n");
    
    return 0;
}

