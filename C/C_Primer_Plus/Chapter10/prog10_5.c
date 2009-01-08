/*
 *  prog10_5.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int maxMinDiff(const int array[], int size);

int main (int argc, const char * argv[]) {
    const int myArray[10] = {5, 84, 51, 15, 9, 6, 8458, 845, 956, 856};
    
    printf("The difference b/t the max and min values of myArray is: %d\n", maxMinDiff(myArray, 10));
    return 0;
}

int maxMinDiff(const int array[], int size) {
    int i;
    int maxIndex = 0;
    int minIndex = 0;
    
    for (i = 0; i < size; i++) {
        maxIndex = (array[i] > array[maxIndex]) ? i : maxIndex; 
        minIndex = (array[i] < array[minIndex]) ? i : minIndex; 
    }
    
    return array[maxIndex] - array[minIndex];
}
