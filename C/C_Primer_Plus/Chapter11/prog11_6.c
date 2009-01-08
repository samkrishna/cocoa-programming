/*
 *  prog11_6.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

char *myStrncpy(char *s1, char *s2, int length);

int main (int argc, const char * argv[]) {
    char s1[35] = "\0";
    char s2[] = "Howdy, folks!";
    
    myStrncpy(s1, s2, 5);
    printf("The new s1 = %s\n", s1);
    printf("The new s2 = %s\n", s2);
    
    return 0;
}

char *myStrncpy(char *s1, char *s2, int length) {
    int i = 0;
    char *ch1 = s1;
    char *ch2 = s2;
    int s2Length = strlen(s2);
    
    while (i++ < length) {
        *ch1 = *ch2;
        ch1++;
        ch2++;
    }
    
    if (i >= length) {
        *ch2 = '\0';
        *ch1 = '\0';
    }
    
    return s1;
}
