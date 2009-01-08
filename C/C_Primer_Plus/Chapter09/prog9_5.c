/*
 *  prog9_5.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void contentSwizzle(int *sum, int *difference);

int main (int argc, const char * argv[]) {
    int val1 = 7;
    int val2 = 11;
    
    printf("before the swizzle, val1 = %d and val2 = %d\n", val1, val2);
    contentSwizzle(&val1, &val2);
    printf("after the swizzle, val1 = %d and val2 = %d\n", val1, val2);
    
    return 0;
}

void contentSwizzle(int *sum, int *difference) {
    int _sum = *sum + *difference;
    int _difference = *sum - *difference;
    
    *difference = _difference;
    *sum = _sum;
}

