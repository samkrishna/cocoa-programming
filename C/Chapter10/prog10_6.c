/*
 *  prog10_6.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define YEARS 5
#define MONTHS 12

void copyByNotation(const double array[], double copyArray[], int size);
void printArray(const double array[], int size);

int main (int argc, const char * argv[]) {
    const double rain[YEARS][MONTHS] = {
        {10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4},
        {9.2,  9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2},
        {6.6,  5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2},
        {4.3,  4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5,  8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2}
    };    
    double rainTwo[YEARS][MONTHS]; 
    int year;
    
    for (year = 0; year < YEARS; year++) {
        copyByNotation(rain[year], rainTwo[year], MONTHS);
    }

    printf("\nOriginal Rain array:\n");
    for (year = 0; year < YEARS; year++) {
        printArray(rain[year], MONTHS);
    }

    printf("\nCopied Rain array:\n");
    for (year = 0; year < YEARS; year++) {
        printArray(rainTwo[year], MONTHS);
    }
    
    return 0;
}

void copyByNotation(const double array[], double copyArray[], int size) {
    int i;
    
    for (i = 0; i < size; i++) {
        copyArray[i] = array[i];
    }
}

void printArray(const double array[], int size) {
    int i;
    
    printf("This array's values: ");
    for (i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

