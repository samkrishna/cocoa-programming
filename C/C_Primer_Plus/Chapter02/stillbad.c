/*
 *  stillbad.c
 *  Chapter2
 *
 *  Created by Sam Krishna on 3/2/09.
 *  Copyright 2009 Chaordium Software. All rights reserved.
 *
 */

#include <stdio.h>

int main(void)
{
    int n, n2, n3;
    
    n = 5;
    n2 = n * n;
    n3 = n2 * n2;
    printf("n = %d, n squared = %d, n cubed = %d.\n", n, n2, n3);
    
    return 0;
}