/*
 *  prog2_6.c
 *  Chapter2
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void smile(void);

int main(void)
{
    int count = 3;
    int i;
    
    while (count-- > 0) {
        for (i = 0; i <= count; i++) {
            smile();
        }
        
        printf("\n");
    }
    
    return 0;
}

void smile(void)
{
    printf("Smile!");
}
