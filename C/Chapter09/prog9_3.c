/*
 *  prog9_3.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void chline2(char ch, int number, int rows);

int main (int argc, const char * argv[]) {
    chline2('*', 4, 5);
    return 0;
}

void chline2(char ch, int number, int rows) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < number; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
}

