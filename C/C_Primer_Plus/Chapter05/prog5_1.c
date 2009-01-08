/*
 *  prog5_1.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int hours = 0;
    int minutes = 0;
    
    printf("Enter the # of minutes you want to convert: ");
    scanf("%d", &minutes);
    
    while (minutes > 60) {
        minutes -= 60;
        hours++;
    }
    
    printf("The total time is %d hours and %d minutes.\n", hours, minutes);
    return 0;
}

