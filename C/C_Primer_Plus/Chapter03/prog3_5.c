/*
 *  prog3_5.c
 *  Chapter3
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int years;
    
    printf("What's your age (in years)? ");
    scanf("%i", &years);
    printf("The approximate number of seconds you've been alive is: %e\n", years * 3.156e7f);
    return 0;
}

