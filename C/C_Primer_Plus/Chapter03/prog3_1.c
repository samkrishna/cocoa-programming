/*
 *  prog3_1.c
 *  Chapter3
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <math.h>

int main (int argc, const char * argv[]) {
    int boundary = (int)pow(2, 32);
    float fBoundary = pow(2.0, 32);
    int i;
    int count = 4096;
    
    printf("sizeof int = %d\n", sizeof(int));
    printf("Boundary condition:\n");
    printf("2^32 = %d\n\n", boundary + 1);
    
    printf("sizeof float = %d\n", sizeof(float));
    printf("Boundary condition:\n");
    printf("overflow: 2^256 = %e\n", pow(2.0, 256));
    printf("overflow: 2^1024 = %e\n", pow(2.0, 1024));
    printf("underflow: 1.0e-37f / 2^1024 = %e\n", 1.0e-37f / pow(2.0, 1024));
    
    return 0;
}

