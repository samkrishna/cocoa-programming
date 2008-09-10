/*
 *  prog9_4.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

double harmonic(double num1, double num2);

int main (int argc, const char * argv[]) {
    printf("The harmonic mean of 3 and 7 is %.3f.\n", harmonic(3, 7));
    return 0;
}

double harmonic(double num1, double num2) {
    return ((2 * num1 * num2) / (num1 + num2));
}
