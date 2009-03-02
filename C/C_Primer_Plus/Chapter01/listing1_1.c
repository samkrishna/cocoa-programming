/*
 *  listing1_1.c
 *  Chapter1
 *
 *  Created by Sam Krishna on 3/2/09.
 *  Copyright 2009 Chaordium Software. All rights reserved.
 *
 */

#include <stdio.h>

int main(void)
{
    int dogs;
    
    printf("How many dogs do you have?\n");
    scanf("%d", &dogs);
    printf("So you have %d dog(s)!\n", dogs);
    
    return 0;
}