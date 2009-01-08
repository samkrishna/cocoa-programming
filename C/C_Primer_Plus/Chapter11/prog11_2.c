/*
 *  prog11_2.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void fetch(int chCount);

int main (int argc, const char * argv[]) {
    int chCount;
    
    printf("How many characters do you want to scan (including newlines, tabs, and spaces)? ");
    scanf("%d", &chCount);
    
    fetch(chCount);
    
    return 0;
}

void fetch(int chCount) {
    int i = 0;
    char ch;
    
    while ((ch = getchar()) && i++ < chCount) {
        switch(ch) {
            case ('\n') :
                if (i == 1 && ch == '\n') {
                    i = 0;
                    break;
                }
                printf("\nDiscovered newline–halting\n");
                return;
                break;
            case (' ') :
                printf("Discovered space-halting\n");
                return;
                break;
            case ('\t') :
                printf("Discovered tab-halting\n");
                return;
                break;
            default :
                printf("%c", ch);
        }
    }
}
