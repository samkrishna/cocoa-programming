/*
 *  prog8_2.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    char ch;
    
    printf("Enter input and use EOF (CTRL-D) to end.\n");
    
    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            printf("\'\\t\'");
            //printf("\n\ntab is %d\n\n", ch);
            continue;
        }
        
        if (ch == '\n') {
            printf("\'\\n\'");
            //printf("\n\nnewline is %d\n\n", ch);
            continue;
        }
        
        if (ch < 27) {
            printf("\'CTRL-%c\'", ch + 64);
        }
        
        if (ch >= 27) {
            printf("%c", ch);
        }
    }
    
    return 0;
}

