/*
 *  prog7_7.c
 *  Chapter7
 *
 *  Created by Sam Krishna on 4/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>

#define PAYRATE 10.0
#define OVERTIME 15.0
#define FIRST_300 0.15
#define NEXT_150 0.2
#define REST_TAX 0.25

int main (int argc, const char * argv[]) {
    float hoursWorked = 0.0;
    float gross = 0.0;
    float taxes = 0.0;
    
    printf("Enter the number of hours worked this week: ");
    scanf("%f", &hoursWorked);
    
    if (hoursWorked <= 40) {
        gross = hoursWorked * PAYRATE;        
    } else {
        gross = 40.0 * PAYRATE;
        gross += (hoursWorked - 40.0) * OVERTIME;
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
    return 0;
}

