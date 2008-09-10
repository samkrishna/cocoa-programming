/*
 *  prog4_2.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int charCount = 0;
    char c;
    
    printf("Enter text, using \'#\' character to halt. Output will print ASCII code-character pairs 8 per line.\n");
    
    while (scanf("%c", &c) && c != '#') {
        if ((++charCount > 0) && (charCount % 8 == 0) ) {
            printf("\n");
        }
        
        if (c == '\n') {
            printf("\\n = %3i\t", c);
        } else if (c == ' ') {
            printf("\' \' = %3i\t", c);
        } else if (c == '\t') {
            printf("\\t = %3i\t", c);
        } else {
            printf("%c = %3i\t", c, c);            
        }
    }
    
    return 0;
}

