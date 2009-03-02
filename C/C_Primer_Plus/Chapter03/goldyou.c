/*
 *  goldyou.c - The worth of your weight in gold
 *  Chapter3
 *
 *  Created by Sam Krishna on 3/2/09.
 *  Copyright 2009 Chaordium Software. All rights reserved.
 *
 */

#include <stdio.h>

int main(void)
{
    float weight;
    float value;
    
    printf("Are you worth your weight in gold?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");
    
    // get input from user
    scanf("%f", &weight);
    // assume gold is $320 USD per ounce
    // 14.5833 converts pounds avd. to ounces troy
    value = 320.0 * weight * 14.5833;
    printf("Your weight in gold is worth $%.2f.\n", value);
    printf("You are easily worth that! If gold prices drop, \n");
    printf("eat more to maintain your value. :-D\n");
    
    return 0;
}