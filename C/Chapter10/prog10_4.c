/*
 *  prog10_4.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
#include <stdio.h>

int maxIndex(const int array[], int size);

int main (int argc, const char * argv[]) {
    const int myArray[10] = {5, 84, 51, 15, 9, 6, 8458, 845, 956, 856};
    
    printf("The index of the maximum value of myArray is: %d\n", maxIndex(myArray, 10));
    return 0;
}

int maxIndex(const int array[], int size) {
    int i;
    int index = 0;
    
    for (i = 0; i < size; i++) {
        index = (array[i] > array[index]) ? i : index; 
    }
    
    return index;
}
