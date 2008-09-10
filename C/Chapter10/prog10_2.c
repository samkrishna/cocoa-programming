/*
 *  prog10_2.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void copyByNotation(const int array[], int copyArray[], int size);
void copyByPointer(const int array[], int *copyArray, int size);
void printArray(const int array[], int size);

int main (int argc, const char * argv[]) {
    const int myArray[10] = {5, 84, 51, 15, 9, 6, 8458, 845, 956, 856};
    int arrayOne[10];
    int arrayTwo[10];
    int i;
    
    copyByNotation(myArray, arrayOne, 10);
    copyByPointer(myArray, arrayTwo, 10);
    
    printArray(myArray, 10);
    printArray(arrayOne, 10);
    printArray(arrayTwo, 10);
    
    return 0;
}

void copyByNotation(const int array[], int copyArray[], int size) {
    int i;
    
    for (i = 0; i < size; i++) {
        copyArray[i] = array[i];
    }
}

void copyByPointer(const int array[], int *copyArray, int size) {
    int i;
    
    // array[m][n] == *(*(array + m) + n)
    for (i = 0; i < size; i++) {
        *(copyArray + i) = *(array + i);
    }
}

void printArray(const int array[], int size) {
    int i;
    
    printf("This array's values: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

