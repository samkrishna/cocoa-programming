/*
 *  prog11_8.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

void reverse(char *string);

int main (int argc, const char * argv[]) {
    char string[] = "reversible";
    
    printf("The reversed string is: ");
    reverse(string);
    printf("%s\n", string); 
    return 0;
}

void reverse(char *string) {
    int length = strlen(string);
    int i = length - 1;
    int j = 0;
    char temp1 = '\0';
    char temp2 = '\0';
    
    while (i > j) {
        temp1 = *(string + j);
        temp2 = *(string + i);
        *(string + j) = temp2;
        *(string + i) = temp1;
        i--;
        j++;
    }
}
