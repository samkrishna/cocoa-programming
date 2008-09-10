/*
 *  wheat.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#define SQUARES 64
#define CROP 9E14

int main (int argc, const char * argv[]) {
    double current, total;
    int count = 1;
    
    printf("square    grains added    total grains    ");
    printf("fraction of \n");
    printf("                                          ");
    printf("US Total\n");
    
    total = current = 1.0;
    printf("%4d %15.2e %13.2e    %13.2e\n", count, current, total, total / CROP);
    
    while (count++ < SQUARES) {
        current *= 2.0;
        total = total + current;
        printf("%4d %15.2e %13.2e    %13.2e\n", count, current, total, total / CROP);
    }
    return 0;
}

