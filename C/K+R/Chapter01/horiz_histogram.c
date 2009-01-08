/*
 *  horiz_histogram.c
 *  Chapter01
 *
 *  Created by Sam Krishna on 1/8/09.
 *  Copyright 2009 Chaordium Software. All rights reserved.
 *
 */

#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN      1
#define OUT     0

// print horizontal histogram
int main (int argc, const char * argv[]) {

    int c, i, nc, state;
    int len;                // Length of each bar
    int maxvalue;           // max value for wl[]
    int ovflow;             // number of overflow words
    int wl[MAXWORD];        // word length counters
    
    state = OUT;
    nc = 0;                 // # of chars in a word
    ovflow = 0;             // # of words >= MAXWORD

    for (i = 0; i < MAXWORD; ++i) {
        wl[i] = 0;
    }
    
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            nc = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            nc = 1;         // beginning of word
        }
        else
            ++nc;           // inside a word
    }
    
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i) {
        if (wl[i] > maxvalue)
            maxvalue = wl[i];
    }
    
    for (i = 1; i < MAXWORD; i++)
    {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0)
        {
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        }
        else
            len = 0;
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    
    if (ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);

    return 0;
}
