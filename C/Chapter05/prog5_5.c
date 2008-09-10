/*
 *  prog5_5.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int dollars = 0, days = 0;
    float total = 0.0;
    
    printf("Gettin' paid, geometric-style!\n");
    printf("How many days do you want to get paid in increasing increments? ");
    scanf("%d", &days);
    
    while (dollars++ < days) {
        total += (dollars * dollars);
        printf("Day %d---Total: %.0f and dollars = %d\n", dollars, total, dollars * dollars);
    }
    
    printf("At the end of the period, you will have made $%.0f.\n", total);
    
    return 0;
}

