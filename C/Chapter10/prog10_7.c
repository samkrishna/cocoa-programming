/*
 *  prog10_7.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void copyByPointer(const double array[], double *copyArray, int size);
void printArray(const double array[], int size);

int main (int argc, const char * argv[]) {
    const double arrayOne[7] = {10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2};
    double arrayTwo[3];
    
    copyByPointer(arrayOne + 2, arrayTwo, 3);
    printf("The msaller copied array:\n");
    printArray(arrayTwo, 3);
    
    return 0;
}

void copyByPointer(const double array[], double *copyArray, int size) {
    int i;
    
    // array[m][n] == *(*(array + m) + n)
    for (i = 0; i < size; i++) {
        *(copyArray + i) = *(array + i);
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


