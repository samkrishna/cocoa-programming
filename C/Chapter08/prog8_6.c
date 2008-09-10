/*
 *  prog8_6.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int getfirst(void);

int main (int argc, const char * argv[]) {
    char ch;
    printf("Enter characters.\n");
    ch = getfirst();
    
    printf("The first character was: %c\n", ch);
    
    return 0;
}

int getfirst(void) {
    int ch;
    
    ch = getchar();
    while (getchar() != ' ') {
        continue;
    }
    
    return ch;
}
