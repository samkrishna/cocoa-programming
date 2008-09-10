/*
 *  prog6_4.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

int main (int argc, const char * argv[]) {
    int i;
    char word[50];

    printf("Enter a word up to 50 characters long: ");
    scanf("%s", &word);
    
    printf("The reverse of %s is ");
    for (i = strlen(word); i >= 0; i--) {
        printf("%c", word[i]);
    }
    
    return 0;
}

