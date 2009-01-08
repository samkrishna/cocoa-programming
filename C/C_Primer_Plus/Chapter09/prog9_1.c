/*
 *  prog9_1.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

double min(double x, double y);

int main (int argc, const char * argv[]) {
    double val = min(17, 14.3);
    printf("The min of 17 and 14.3 is %.2f.\n", val);
    return 0;
}

double min(double x, double y) {
    if (x < y) {
        return x;
    }
    
    return y;
}
