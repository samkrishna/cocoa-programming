/*
 *  prog12_1.c
 *  Chapter4
 *
 *  Created by Sam Krishna on 4/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char * argv[]) {
    FILE *in;
    FILE *out;
    char line[50];
    
    if (argc != 3) {
        printf("Usage: %s filename1 filename2\n", argv[0]);
        exit(1);
    }
    
    if ((in = fopen(argv[1], "rb")) == NULL) {
        printf("Can't open %s.\n", argv[1]);
        exit(1);
    }
    
    if ((out = fopen(argv[2], "wb")) == NULL) {
        printf("Can't open %s.\n", argv[2]);
        exit(2);
    }
    
    printf("Opened both %s and %s.\n", argv[1], argv[2]);

    while (fgets(line, 50, in) != NULL) {
        fputs(line, out);
    }
    
    fclose(in);
    fclose(out);
    printf("Both %s and %s are closed.\n", argv[1], argv[2]);
    
    return 0;
}

