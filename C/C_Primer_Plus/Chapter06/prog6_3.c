/*
 *  prog6_3.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int lower, upper;
    printf("Enter lower and upper bounds of table: ");
    scanf("%d %d", &lower, &upper);
    
    for (; lower <= upper; lower++) {
        printf("integer: %5d squared: %5d cubed: %5d\n", lower, lower * lower, lower * lower * lower); 
    }
    
    return 0;
}

