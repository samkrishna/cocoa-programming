/*
 *  prog5_5.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

float cubed(float value);

int main (int argc, const char * argv[]) {
    float val = 0.0;
    printf("Enter a positive value to cube: ");
    scanf("%f", &val);
    printf("The value cubed is %.3f\n", cubed(val));
    
    return 0;
}

float cubed(float value) {
    return value * value * value;
}

