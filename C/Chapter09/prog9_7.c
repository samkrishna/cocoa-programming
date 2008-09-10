/*
 *  prog9_7.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

double power(double x, int y);

int main (int argc, const char * argv[]) {
    printf("2^-2 is %.4f\n", power(2, -2));
    printf("7^-3 is %.4f\n", power(7, -3));
    return 0;
}

double power(double x, int y) {
    double pow = 1;
    int i;
    
    if (x == 0) {
        return 0;
    }
    
    if (y == 0) {
        return 1;
    }
    
    if (y > 0) {
        for (i = 1; i <= y; i++) {
            pow *= x;
        }        
    } else {
        for (i = -1; i >= y; i--) {
            pow *= (1.0 / x);
        }                
    }
        
    return pow;
}
