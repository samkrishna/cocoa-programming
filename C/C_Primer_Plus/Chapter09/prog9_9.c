/*
 *  prog9_9.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

void to_binary(int n, int base);

int main (int argc, const char * argv[]) {
    int number;
    int base;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%d", &number) == 1) {
        printf("Enter a base (2-10): ");
        scanf("%d", &base);
        printf("Binary equivalent: ");
        to_binary(number, base);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");        
    }
    
    return 0;
}

void to_binary(int n, int base) {
    int r;
    
    r = n % base;
    if (n >= base) {
        to_binary(n / base, base);
    }
    
    putchar('0' + r);
    return;
}
