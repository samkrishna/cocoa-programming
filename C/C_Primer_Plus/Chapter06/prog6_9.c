/*
 *  prog6_9.c
 *  Chapter6
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <math.h>

int main (int argc, const char * argv[]) {
    int i, array[8];
    
    for (i = 0; i < 8; i++) {
        array[i] = pow(2, i);
    }
    
    i = 0;
    
    do {
        printf("array[2 ^ %i] = %i\n", i, array[i]);
    } while (++i < 8);
    
    return 0;
}

