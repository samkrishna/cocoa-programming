/*
 *  prog7_10.c
 *  Chapter7
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define SINGLE 17850
#define HEAD 23900
#define JOINT 29750
#define SEPARATE 14875

void menu(void);

int main (int argc, const char * argv[]) {
    int rateChoice;
    int ceiling = 0;
    float income = 0.0;
    float taxes = 0.0;
    menu();
    
    while ((rateChoice = getchar()) != '5') {
        switch (rateChoice) {
            case ('1') :
                ceiling = SINGLE;
                break;
            case ('2') :
                ceiling = HEAD;
                break;
            case ('3') :
                ceiling = JOINT;
                break;
            case ('4') :
                ceiling = SEPARATE;
                break;
        }
        
        printf("Enter taxable income earned: \n");
        scanf("%f", &income);
        
        if (income > ceiling) {
            taxes += ceiling * 0.15;
            taxes += (income - ceiling) * 0.28;
        } else {
            taxes += ceiling * 0.15;            
        }
        
        printf("Income: %.2f and taxes: %.2f\n", income, taxes);
        income = 0.0;
        taxes = 0.0;
        menu();
        rateChoice = getchar();
    }
        
    return 0;
}

void menu(void) {
    printf("\nChoose a tax category:\n");
    printf("1) Single\t\t\t\t2) Head of Household\n");
    printf("3) Married, Joint\t\t4) Married, Separate\n");
    printf("5) Quit\n");
}
