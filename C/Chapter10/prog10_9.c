/*
 *  prog10_9.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void printArray(double array[][5], int rows);
void doubleArray(double array[][5], int rows);
void copyArray(const double array[][5], double newArray[][5], int rows);

int main (int argc, const char * argv[]) {
    const double rain[3][5] = {
        {10.2, 8.1, 6.8, 4.2, 2.1},
        {9.2,  9.8, 4.4, 3.3, 2.2},
        {6.6,  5.5, 3.8, 2.8, 1.6}
    };
    double newArray[3][5];
    
    copyArray(rain, newArray, 3);
    printf("New rain array:\n");
    printArray(newArray, 3);
    doubleArray(newArray, 3);
    printf("\nDoubled new rain array:\n");
    printArray(newArray, 3);

    return 0;
}


void doubleArray(double array[][5], int rows) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            array[i][j] *= 2.0;
        }
    }
}

void copyArray(const double array[][5], double newArray[][5], int rows) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            newArray[i][j] = array[i][j];
        }
    }
}


void printArray(double array[][5], int rows) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            printf("%.2f ", array[i][j]);
        }
        printf("\n");
    }
}
