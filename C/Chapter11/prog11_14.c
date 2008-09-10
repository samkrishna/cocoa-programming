/*
 *  prog11_14.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <ctype.h>

void toUpper(char *string);
void toLower(char *string);

int main (int argc, const char * argv[]) {
    char string[250];
    
    printf("Please enter a string to process:\n");
    while (gets(string) && *string != EOF) {
        if (strcmp("-l", argv[1]) == 0) {
            toLower(string);
        }
        
        if (strcmp("-u", argv[1]) == 0) {
            toUpper(string);
        }
        
        printf("The input string is:\n%s\n", string);
        printf("\nPlease enter a string to process:\n");
    } 
    
    return 0;
}

void toUpper(char *string) {
    while (*string != '\0') {
        *string = toupper(*string);
        string++;
    }
}

void toLower(char *string) {
    while (*string != '\0') {
        *string = tolower(*string);
        string++;
    }
}
