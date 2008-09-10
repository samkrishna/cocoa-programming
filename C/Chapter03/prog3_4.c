/*
 *  prog3_4.c
 *  Chapter3
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    float fpNumber;
    printf("Enter a floating-point number: ");
    scanf("%f", &fpNumber);
    printf("The input is %f or %e", fpNumber, fpNumber);
    
    return 0;
}
