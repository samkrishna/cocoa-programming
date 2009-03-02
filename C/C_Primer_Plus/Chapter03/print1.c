/*
 *  print1.c - displays some properties of printf
 *  Chapter3
 *
 *  Created by Sam Krishna on 3/2/09.
 *  Copyright 2009 Chaordium Software. All rights reserved.
 *
 */

#include <stdio.h>

int main(void)
{
    int ten = 10;
    
    printf("Doing it right: ");
    printf("%d minus %d is %d\n", ten, 2, ten - 2);
    printf("Doing it wrong: ");
    printf("%d minus %d is %d\n", ten);

    // OK, on my 24" iMac with a 64-bit processor, for some reason this actually displays the right information.
    /*
     Doing it right: 10 minus 2 is 8
     Doing it wrong: 10 minus 2 is 8
    */
    
    // It's very bizarre. It works the same on both Debug and Release builds. Perhaps worth filing a bug over? I don't know....
    return 0;
}