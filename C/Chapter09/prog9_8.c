/*
 *  prog9_8.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

double rpower(double x, int y);

int main (int argc, const char * argv[]) {
    printf("2^3 is %.4f\n", rpower(2, 3));
    printf("2^-2 is %.4f\n", rpower(2, -2));
    printf("7^-3 is %.4f\n", rpower(7, -3));
    printf("0^-3 is %.4f\n", rpower(0, -3));
    return 0;
}

double rpower(double x, int y) {
    double pow = (y < 0 && x > 0) ? (1.0 / x) : x;
    int i;
    
    if (x == 0) {
        return 0;
    }
    
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x;
    }

    if (y > 0) {
        pow *= rpower(x, --y);        
    } else {
        pow *= rpower(x, ++y);
    }
    
    return pow;
}
