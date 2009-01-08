/*
 *  prog6_8.c
 *  Chapter6
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int limit, i;
    float series1total = 0;
    float series2total = 0;
    printf("Enter a term-limit to evaluate two different infinite series (must be positive integer): ");
    scanf("%i", &limit);
    
    for (i = 1; i <= limit; i++) {
        // printf("current %d-th value is: %.6f\n", i, (1.0 / i));
        series1total += (1.0 / i);
        series2total += (i % 2 == 1) ? (1.0 / i) : (-1.0 / i);
    }
    
    printf("The first series, evaluated to %d terms, is: %f\n", limit, series1total);
    printf("The second series, evaluated to %d terms, is: %f\n", limit, series2total); 
    return 0;
}

