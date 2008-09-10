/*
 *  prog4_4.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    float inches;
    char name[30];
    
    printf("What is your height (in inches) and your name: ");
    scanf("%f %s", &inches, &name);
    printf("%s, you are %.3f feet tall.", name, inches / 12);
    
    return 0;
}

