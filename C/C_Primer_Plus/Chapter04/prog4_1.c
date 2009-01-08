/*
 *  prog4_1.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    char firstName[30];
    char lastName[30];
    
    printf("Enter your first name: ");
    scanf("%s", &firstName);
    printf("Enter your last name: ");
    scanf("%s", &lastName);
    printf("Your name is %s, %s.\n", lastName, firstName);
    
    return 0;
}

