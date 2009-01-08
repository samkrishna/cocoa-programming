/*
 *  prog5_4.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int total = 0, dollars = 0, days = 0;
    
    printf("Gettin' paid, fibonnacci-style!\n");
    printf("How many days do you want to get paid in increasing increments? ");
    scanf("%d", &days);
    
    while (dollars++ < days) {
        total += dollars;
    }
    
    printf("At the end of the period, you will have made $%d.\n", total);
    
    return 0;
}

