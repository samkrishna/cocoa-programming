/*
 *  prog3_2.c
 *  Chapter3
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <math.h>

int main (int argc, const char * argv[]) {
    int asciiCode = 0;
    printf("Enter an ASCII value (0-127): ");
    scanf("%d", &asciiCode);
    printf("The ASCII value %d = %c\n", asciiCode, asciiCode);
    return 0;
}
