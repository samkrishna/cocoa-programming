/*
 *  prog3_6.c
 *  Chapter3
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int quarts;
    int quartMass = 950;
    float h20MolMass = 3.0e-23f;
    
    printf("Enter the number of quarts of water for molecular count analysis: ");
    scanf("%i", &quarts);
    printf("The number of molecules for %i quarts = %e molecules.\n", quarts, (quarts * quartMass) / h20MolMass);
    return 0;
}

