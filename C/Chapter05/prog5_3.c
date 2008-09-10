/*
 *  prog5_3.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int days, weeks = 0;
    
    printf("Enter the number of days and I'll convert it for you: ");
    scanf("%d", &days);
    
    while (days > 7) {
        days -= 7;
        weeks++;
    }
    
    printf("There are %d weeks and %d days.\n", weeks, days);
    return 0;
}

