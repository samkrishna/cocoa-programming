/*
 *  fathm_ft.c
 *  Chapter2
 *
 *  Created by Sam Krishna on 3/2/09.
 *  Copyright 2009 Chaordium Software. All rights reserved.
 *
 */

// converts 2 fathms to feet
#include <stdio.h>

int main(void)
{
    int feet, fathoms;
    fathoms = 2;
    feet = 6 *fathoms;
    printf("There are %d feet in %d fathoms!\n", feet, fathoms);
    
    return 0;
}