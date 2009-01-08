/*
 *  prog6_2.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    char dollar = '$';
    char F = 'F';
    char letter, currentLetter;
    char space = ' ';
    
    int i, j, k, l;
    /*
    for (i = 0; i < 5; i++) {
        j = i;
        while (j-- > -1) {
            printf("%c", dollar);
        }
        printf("\n");
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j <= i; j++) {
            printf("%c", F - j);
        }
        printf("\n");
    }
    */
    printf("Enter a leter as the axis-pivot: ");
    scanf("%c", &letter);

    // Loop for number of rows (ex. 'E' will produce 5 rows)
    for (i = 0, currentLetter = 'A'; i < (letter - 'A' + 1); i++, currentLetter++) {
        // Nice debugging trick to give state w/o confusing the display
        //printf("Number of spaces to print: %d\n", letter - currentLetter);
        //printf("Current pivot letter: %c\n", currentLetter);
        
        // Loop to handle spaces
        for (j = 0; j <= (letter - currentLetter); j++) {
            printf(" ");
        }
        
        // Loop to print letters in ascending order
        // We let the descending loop be the dominant loop and
        // the ascending loop be the subordinate loop
        for (k = 'A'; k < currentLetter; k++) {
            printf("%c", k);
        }
        
        // Loop to print letters in descending order
        for (l = currentLetter; l >= 'A'; l--) {
            printf("%c", l);
        }
        
        printf("\n");
    }
    
    return 0;
}

