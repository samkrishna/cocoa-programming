/*
 *  prog11_9.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

void removeSpace(char *string);

int main (int argc, const char * argv[]) {
    char string[100];
    char ch;
    int i = 0;
    
    printf("Enter input: \n");
    while (gets(string) && string[0] != '\0') {
        removeSpace(string);
        printf("The new sentence: %s\n", string);        
    }
    
    return 0;
}

void removeSpace(char *string) {
    char ch;
    int i = 0;
    int j = 0;
    int length = strlen(string);
    char newstring[length];
    
    while (i < length) {
        ch = string[i++];
        
        if (ch != ' ') {
            newstring[j++] = ch;            
        }
    }
    
    newstring[j] = '\0';
    string = strcpy(string, newstring);
}
