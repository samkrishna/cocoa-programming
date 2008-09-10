/*
 *  prog6_12.c
 *  Chapter6
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    float money = 1e6;
    int withdrawal = 100000;
    float rate = 1.08;
    int i;
    
    for (i = 1; i < 50; i++) {
        money *= rate;
        money -= withdrawal;
        
        if (money <= 0.0) {
            printf("It took %i years to empty Chuck's account.\n", i);
            break;
        }
    }
    
    return 0;
}