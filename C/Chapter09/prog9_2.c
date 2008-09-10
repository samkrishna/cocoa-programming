/*
 *  prog9_2.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void chline(char ch, int i, int j);

int main (int argc, const char * argv[]) {
    chline('a', 5, 15);
    return 0;
}

void chline(char ch, int i, int j) {
    int k = 0;

    printf("%*c", i, ch);
    for (k = i; k < j; k++) {
        printf("%c", ch);
    }
}