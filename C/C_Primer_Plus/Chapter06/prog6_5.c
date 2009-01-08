/*
 *  prog6_5.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    float one, two;
    
    printf("Enter two floating-point numbers: \n");
    
    while (scanf("%f %f", &one, &two)) {
        printf("one: %.4f two: %.4f\n", one, two);
        printf("The difference divided by the product is: %.4f\n", (one - two) / (one * two));
    }
    
    return 0;
}

