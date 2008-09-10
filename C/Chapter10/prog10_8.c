/*
 *  prog10_8.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void printArray(const double array[], int size);
void sumArrays(const double *summand1, const double *summand2, double *sum, int size);

int main (int argc, const char * argv[]) {
    const double myArray[10] = {5, 84, 51, 15, 9, 6, 8458, 845, 956, 856};    
    const double myArrayTwo[10] = {6, 87, 51, 15, 9, 6, 3, 845, 3, 856};
    double newArray[10];
    
    sumArrays(myArray, myArrayTwo, newArray, 10);
    printf("New Array:\n");
    printArray(newArray, 10);
    
    return 0;
}

void sumArrays(const double *summand1, const double *summand2, double *sum, int size) {
    int i;
    
    for (i = 0; i < size; i++) {
        sum[i] = *(summand1 + i) + *(summand2 + i);
    }
}

void printArray(const double array[], int size) {
    int i;
    
    printf("This array's values: ");
    for (i = 0; i < size; i++) {
        printf("%.1f ", array[i]);
    }
    printf("\n");
}



