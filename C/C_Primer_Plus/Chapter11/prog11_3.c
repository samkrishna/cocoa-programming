/*
 *  prog11_3.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void fetchWord(int chCount);

int main (int argc, const char * argv[]) {
    int chCount;
    
    printf("How many characters do you want to scan (including newlines, tabs, and spaces)? ");
    scanf("%d", &chCount);
    
    fetchWord(chCount);
    
    return 0;
}

void fetchWord(int chCount) {
    int i = -1;
    char ch;
    
    while ((ch = getchar()) && i++ < chCount) {
        switch(ch) {
            case ('\n') :
                if (i == 0 && ch == '\n') {
                    break;
                }
                printf("\nFound word---Discovered newline+halting\n");
                return;
                break;
                case (' ') :
                printf("\nFound word---Discovered space+halting\n");
                return;
                break;
                case ('\t') :
                printf("\nFound word---Discovered tab+halting\n");
                return;
                break;
                default :
                printf("%c", ch);
        }
    }
}
