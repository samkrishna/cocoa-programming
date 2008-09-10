/*
 *  prog4_3.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    float input;
    
    printf("Enter a floating-point number: ");
    scanf("%f", &input);
    printf("The input is %.3f or %.3e.\n", input, input);
    printf("The input is +%.3f or %.3E.\n", input, input);
    
    return 0;
}

