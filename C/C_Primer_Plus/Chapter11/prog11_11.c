/*
 *  prog11_11.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int punct_ct(const char *string);
int word_ct(const char *string);
int upper_ct(const char *string);
int lower_ct(const char *string);

int main (int argc, const char * argv[]) {
    char string[150];
    int pCount = 0;
    int wCount = 0;
    int uCount = 0;
    int lCount = 0;
    
    while (gets(string) && *string != EOF) {
        pCount += punct_ct(string);
        wCount += word_ct(string);
        uCount += upper_ct(string);
        lCount += lower_ct(string);
    }
    
    printf("punctuation = %d words = %d uppercase = %d lowercase = %d\n", pCount, wCount, uCount, lCount);
    
    return 0;
}

int punct_ct(const char *string) {
    int ct = 0;
    
    while (*string != '\0') {
        if (ispunct(*string)) ct++;
        string++;
    }
    
    return ct;
}

int word_ct(const char *string) {
    int ct = 0;
    
    while (*string != '\0') {
        if (*string == ' ') ct++;
        string++;
    }
    
    return ct;    
}

int upper_ct(const char *string) {
    int ct = 0;
    
    while (*string != '\0') {
        if (isupper(*string)) ct++;
        string++;
    }
    
    return ct;
}

int lower_ct(const char *string) {
    int ct = 0;
    
    while (*string != '\0') {
        if (islower(*string)) ct++;
        string++;
    }
    
    return ct;    
}
