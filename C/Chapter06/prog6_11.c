/*
 *  prog6_11.c
 *  Chapter6
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    float Daphne = 100.0;
    float Diedre = 100.0;
    int i;
    
    //printf("Here's what the investments look like over the next 50 years...\n");
    //printf("year    Diedre's investment     Daphne's investment\n");
    
    for (i = 1; i < 50; i++) {
        Daphne += 10.0;
        Diedre *= 1.05;
        //printf("%2i         %.2f                %.2f\n", i, Diedre, Daphne);
        
        if (Diedre > Daphne) {
            printf("It took %i years for Diedre's investments to surpass Daphne\'s.\n", i);
            printf("Diedre's investment is worth %.2f and Daphne's is worth %.2f\n", Diedre, Daphne);
            break;
        }
    }
    
    return 0;
}

