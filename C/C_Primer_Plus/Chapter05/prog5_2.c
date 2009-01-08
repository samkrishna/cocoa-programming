/*
 *  prog5_2.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int number = 0;
    int final = 0;
    
    printf("Enter a number and I will count it! ");
    scanf("%d", &number);
    final = number + 10;

    while (number < final) {
        printf("%d\n", ++number);
    }
    
    return 0;
}

