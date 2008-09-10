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
    int evenTotal = 0;
    int evenCount = 0;
    int oddCount = 0;
    int oddTotal = 0;
    int integer = 0;
    
    printf("Enter integers and then enter \'0\' to end the input and sum and average the numbers.\n");
    
    while (scanf("%i", &integer) && integer != 0) {
        if (integer % 2 == 0) {
            evenTotal += integer;
            evenCount++;
        } else {
            oddTotal += integer;
            oddCount++;
        }
    }
    
    printf("The total # of even integers is %i and the average is %.3f\n", evenCount, (float)(evenTotal / evenCount));
    printf("The total # of odd integers is %i and the average is %.3f\n", oddCount, (float)(oddTotal / oddCount));
    
    return 0;
}

