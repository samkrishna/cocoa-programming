/*
 *  prog2_4.c
 *  Chapter2
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void jolly(void);
void nobody(void);

int main(void)
{
    jolly();
    jolly();
    jolly();
    nobody();
    
    return 0;
}

void jolly(void) {
    printf("For he's a jolly good fellow!\n");
}

void nobody(void) {
    printf("Which nobody can deny!\n");
}
