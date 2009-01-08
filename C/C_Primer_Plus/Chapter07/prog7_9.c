/*
 *  prog7_9.c
 *  Chapter7
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define NO 0
#define YES 1

long isPrime(long num);

int main (int argc, const char * argv[]) {
    long num;
    long primes[50];
    long i;
    int j = 0;
    int k = 0;
    long candidate;
    
    printf("Please enter an integer for analysis; Enter q to quit\n");
    
    while (scanf("%ld", &num) == 1) {
        for (i = 2; i <= num; i++) {
            candidate = isPrime(i);
            
            if (candidate != 0) {
                primes[j++] = candidate;
            }
        }
        
        printf("The integers that are prime between 1 and %ld are:\n", num);
        
        for (k = 0; k < j; k++) {
            printf("%ld ", primes[k]);
        }
        
        // Clean the primes array
        for (k = 0; k < j; k++) {
            primes[k] = '\0';
        }
        j = 0;
        
        printf("\nPlease enter another integer for analysis; ");
        printf("Enter q to quit.\n");
    }
    return 0;
}

long isPrime(long num) {
    long div;
    int prime;
    
    for (div = 2, prime = YES; (div * div) <= num; div++) {
        if (num % div == 0) {
            return 0;
        }
    }
    
    return num;
}
