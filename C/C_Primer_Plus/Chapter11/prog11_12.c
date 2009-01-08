/*
 *  prog11_12.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

int main (int argc, const char * argv[]) {
    int i;
    
    for (i = argc - 1; i > 0; i--) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    
    return 0;
}


