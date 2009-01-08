/*
 *  prog4_2.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

/*
                 Sam 
 */
#include <stdio.h>
#include <string.h>

int main (int argc, const char * argv[]) {
    char firstName[30];
    
    printf("Enter your first name: ");
    scanf("%s", &firstName);
    printf("Your first name is: \"%*s\"\n", 20, firstName);
    printf("Your first name is: \"%-*s\"\n", 20, firstName);
    printf("Your first name is: \"%-*s\"\n", strlen(firstName) + 3, firstName);
    
    return 0;
}

