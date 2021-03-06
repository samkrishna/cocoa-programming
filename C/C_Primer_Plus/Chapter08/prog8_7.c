/*
 *  prog8_7.c
 *  Chapter11
 *
 *  Created by Sam Krishna on 4/21/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define FIRST_300 0.15
#define NEXT_150 0.2
#define REST_TAX 0.25

void menu(void);

int main (int argc, const char * argv[]) {
    float hoursWorked = 0.0;
    float gross = 0.0;
    float taxes = 0.0;
    int rateChoice;
    float payRate;
    float otRate;
    
    menu();
    
    while ((rateChoice = getchar()) != 'e') {
        switch (rateChoice) {
            case ('a') :
                payRate = 8.75;
                break;
            case ('b') :
                payRate = 9.33;
                break;
            case ('c') :
                payRate = 10.0;
                break;
            case ('d') :
                payRate = 11.20;
                break;
        }
        
        printf("Enter total hours worked: \n");
        scanf("%f", &hoursWorked);
        
        if (hoursWorked <= 40) {
            gross = hoursWorked * payRate;        
        } else {
            gross = 40.0 * payRate;
            gross += (hoursWorked - 40.0) * (payRate * 1.5);
        }
        
        if (gross > 450.0) {
            taxes += REST_TAX * (gross - 450.0);
            taxes += NEXT_150 * 150;
            taxes += FIRST_300 * 300;        
        } else if (gross > 300.0 && gross <= 450.0) {
            taxes += NEXT_150 * (gross - 300.0);
            taxes += FIRST_300 * 300.0;        
        } else {
            taxes += FIRST_300 * gross;
        }
        
        printf("Gross is %.2f\tTaxes are %.2f\tNet pay is %.2f\n\n", gross, taxes, (gross - taxes));
        gross = 0.0;
        taxes = 0.0;
        menu();
        rateChoice = getchar();
    }
    
    return 0;
}

void menu(void) {
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr\t\t\tb) $9.33/hr\n");
    printf("c) $10.00/hr\t\t\td) $11.20/hr\n");
    printf("e) quit\n\n");    
}
