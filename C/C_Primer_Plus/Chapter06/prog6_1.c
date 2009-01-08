/*
 *  prog6_1.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    char letters[26];
    char a = 'a';
    int i;
    
    for (i = 0; i < 26; i++) {
        letters[i] = a++;
    }
    
    letters[i] = '\0';
    printf("letters: %s", letters);
    return 0;
}

