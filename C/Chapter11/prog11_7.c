/*
 *  prog11_7.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define YES 1
#define NO 0

char *string_in(char *s1, char *s2);

int main (int argc, const char * argv[]) {
    char *loc = NULL;
    
    loc = string_in("heart hats for sale", "at");
    
    if (loc != NULL) {
        printf("loc is at %s\n", loc);
    } else {
        printf("The string was not found.\n");
    }
    
    return 0;
}

char *string_in(char *s1, char *s2) {
    char *s2Ptr = s2;
    char *s1Ptr = s1;
    char *mark = NULL;
    
    while (*s1Ptr != '\0' && *s2Ptr != '\0') {
        if (*s1Ptr != *s2Ptr) {
            s1Ptr++;
            s2Ptr = s2;
            mark = NULL;
            continue;
        } else {
            mark = (mark == NULL) ? s1Ptr : mark;
            s2Ptr++;
            s1Ptr++;
        }
    }
    
    return mark;
}
