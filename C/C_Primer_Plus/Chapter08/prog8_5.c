/*
 *  prog8_5.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int guess = 50;
    int low = 1;
    int high = 100;
    char response;
    
    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with a y if my guess is right and with");
    printf("\na l if it is low and an h if it is high.\n");
    printf("Uh... is your number %d?\n", guess);
    
    while ((response = getchar()) != 'y') {
        // int mid = low + ((high - low) / 2);
        if (response == 'l') {
            low = guess;
        } 
        
        if (response == 'h') {
            high = guess;
        }
        
        guess = low + ((high - low) / 2);        
        printf("Well, then, is it %d?\n", guess);
    }
    
    printf("I knew I could do it!\n");
    
    return 0;
}

