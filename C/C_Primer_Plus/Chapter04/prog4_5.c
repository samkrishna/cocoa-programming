/*
 *  prog4_5.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

int main (int argc, const char * argv[]) {
    char firstName[30];
    char lastName[30];
    
    printf("Enter your first and last name: ");
    scanf("%s %s", &firstName, &lastName);
    
    printf("%s %s\n", firstName, lastName);
    printf("%*d %*d\n", strlen(firstName), strlen(firstName), strlen(lastName), strlen(lastName));
    printf("%s %s\n", firstName, lastName);
    printf("%-*d %-*d\n", strlen(firstName), strlen(firstName), strlen(lastName), strlen(lastName));
    return 0;
}

