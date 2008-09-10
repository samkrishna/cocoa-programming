/*
 *  prog11_10.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

void menu(void);
void convertToASCII(char array[][100], int lines);
void printByStringLength(char array[][100], int lines);
void printByWordLength(char array[][100], int lines);
void printArray(char array[][100], int lines);

int main (int argc, const char * argv[]) {
    char stringArray[10][100];
    int i = 0;
    char choice = 0;
    
    printf("Enter up to 10 strings of up to 100 characters each.\n");
    
    // Get the input
    while (gets(stringArray[i]) && stringArray[i][0] != '\0' && i < 10) {
        i++;
    }
    
    menu();
    while ((choice = getchar()) != '5') {
        switch (choice) {
            case('1') :
                printArray(stringArray, i);
                break;
            case('2') :
                convertToASCII(stringArray, i);
                break;
            case('3') :
                printByStringLength(stringArray, i);
                break;
            case('4') :
                printByWordLength(stringArray, i);
                break;
            default :
                continue;
                break;
        }

        menu();
    }
    return 0;
}

void menu(void) {
    printf("\n****************************************************************\n");
    printf("Enter the number corresponding to the desired action:\n");
    printf("1) Print the original list of strings\n");
    printf("2) Print the strings in ASCII collating sequence\n");
    printf("3) Print the strings in order of increasing length.\n");
    printf("4) Print the strings in order of the length of the first word.\n");
    printf("5) quit\n");
    printf("****************************************************************\n");
}

void printArray(char array[][100], int lines) {
    int i;
    for (i = 0; i < lines; i++) {
        printf("%s\n", array[i]);
    }
}

void convertToASCII(char array[][100], int lines) {
    int i, j;
    int length;
    for (i = 0; i < lines; i++) {
        printf("Sentence %d: %s\n", i, array[i]);
        length = strlen(*(array +i));
        for (j = 0; j < length; j++) {
            printf("%d ", array[i][j]);            
        }
        printf("\n");
    }    
}

void printByStringLength(char array[][100], int lines) {
    char *temp;
    int top, seek;
    char *strings[10];
    
    // initialize the strings array before soring
    for (top = 0; top < lines; top++) {
        strings[top] = array[top];
    }
    
    for (top = 0; top < (lines - 1); top++) {
        for (seek = top + 1; seek < lines; seek++) {
            if (strlen(strings[top]) > strlen(strings[seek])) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
    
    for (top = 0; top < lines; top++) {
        printf("%s\n", strings[top]);
    }
}


void printByWordLength(char array[][100], int lines) {
    char *temp;
    int top, seek;
    char *topPtr, *seekPtr;
    char *strings[10];
    int w1Length, w2Length;
    
    // initialize the strings array before soring
    for (top = 0; top < lines; top++) {
        strings[top] = array[top];
    }
    
    // Since there doesnt' *seem* to be a good function to do word isolation
    // on pre-created strings (I was hoping for scanf() <sigh>
    // use pointer math to determine length of first word based upon
    // location of space.
    
    for (top = 0; top < (lines - 1); top++) {
        for (seek = top + 1; seek < lines; seek++) {
            topPtr = strchr(strings[top], ' ');
            seekPtr = strchr(strings[seek], ' ');
            w1Length = (topPtr != '\0') ? (topPtr - strings[top]) : strlen(strings[top]);
            w2Length = (seekPtr != '\0') ? (seekPtr - strings[seek]) : strlen(strings[seek]);
            
            if (w1Length > w2Length) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
    
    for (top = 0; top < lines; top++) {
        printf("%s\n", strings[top]);
    }
}
