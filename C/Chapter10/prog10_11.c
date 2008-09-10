/*
 *  prog10_11.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define ROWS 3

void storage(double array[][5], int rows);
void avgOfSets(double array[][5], int rows);
double avgOfMatrix(double array[][5], int rows);
double maxValue(double array[][5], int rows);
void printArray(double array[][5], int rows);

int main (int argc, const char * argv[]) {
    double array[3][5] = {
        {10.2, 8.1, 6.8, 4.2, 2.1},
        {9.2,  9.8, 4.4, 3.3, 2.2},
        {6.6,  5.5, 3.8, 2.8, 1.6}
    };
    
    // storage(array, ROWS);
    printArray(array, ROWS);
    avgOfSets(array, ROWS);
    printf("avg value of matrix: %.2f\n", avgOfMatrix(array, ROWS));
    printf("max value of matrix: %.2f\n", maxValue(array, ROWS));
    
    return 0;
}

void storage(double array[][5], int rows) {
    int i, j;
    float val = 0.0;
    
    printf("Enter double values, in sets of 5 (you will be prompted for each new rows):\n");
    scanf("%f", &val);
    

    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%f", &val);
            array[i][j] = val;
        }
        printf("Please enter values for new row:\n");
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


void avgOfSets(double array[][5], int rows) {
    double values[5];
    int i, j;
    float rowTotal = 0;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            rowTotal += array[i][j];            
        }
        
        printf("row %d average: %.2f\n", i, rowTotal / 5);
        rowTotal = 0;
    }
}

double avgOfMatrix(double array[][5], int rows) {
    double total = 0;
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            total += array[i][j];            
        }
    }
    
    return total / 15;
}

double maxValue(double array[][5], int rows) {
    double max = array[0][0];
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < 5; j++) {
            max = (array[i][j] > max) ? array[i][j] : max;
        }
    }
    
    return max;
}

