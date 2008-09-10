/*
 *  prog10_10.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define MONTHS 12
#define YEARS 5

void sum_rainfall(const float rainfall[][MONTHS]);
void find_avgs(const float rainfall[][MONTHS]);

int main (int argc, const char * argv[]) {
    
    // Initializing rainfall data for years 1990-1994
    const float rain[YEARS][MONTHS] = {
        {10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4},
        {9.2,  9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2},
        {6.6,  5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2},
        {4.3,  4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5,  8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2}
    };
    
    sum_rainfall(rain);
    find_avgs(rain);
    
    printf("\n");
    return 0;
}

void sum_rainfall(const float rainfall[][MONTHS]) {
    int year, month;
    float subtotal, total;
    
    // array[m][n] == *(*(array + m) + n)
    
    for (year = 0, total = 0; year < YEARS; year++) {
        // sum rainfall for each year
        for (month = 0, subtotal = 0; month < MONTHS; month++) {
            subtotal += *(*(rainfall + year) + month);
        }
        printf("%5d %15.1f\n", 1990 + year, subtotal);
        total += subtotal;
    }

    printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
}

void find_avgs(const float rainfall[][MONTHS]) {
    int month, year;
    float subtotal;
    
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    for (month = 0; month < MONTHS; month++) {
        for (year = 0, subtotal = 0; year < YEARS; year++) {
            subtotal += *(*(rainfall + year) + month);
        }
        printf("%4.1f ", subtotal / YEARS);
    }    
}

