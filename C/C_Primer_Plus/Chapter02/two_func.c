/*
 *  two_func.c
 *  Chapter2
 *
 *  Created by Sam Krishna on 3/2/09.
 *  Copyright 2009 Chaordium Software. All rights reserved.
 *
 */

#include <stdio.h>

void butler(void);  // prototype

int main(void)
{
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and blank DVD-ROMS.\n");
    
    return 0;
}

void butler(void)
{
    printf("You rang, sir?\n");
}