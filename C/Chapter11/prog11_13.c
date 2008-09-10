/*
 *  prog11_13.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double rpower(double x, int y);

int main (int argc, const char * argv[]) {
    const char *number = argv[2];
    int power = atoi(number);
    float base = atof(argv[1]);
    float result = rpower(base, power);
    
    printf("result is %.3f\n", result);
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
