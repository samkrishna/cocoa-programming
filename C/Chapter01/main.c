#include <stdio.h>

int main (int argc, const char * argv[]) {
    
    float inches;
    
    // insert code here...
    printf("Enter the number of inches for conversion: ");
    scanf("%f", &inches);
    printf("The number of centimeters is: %.2f\n", inches * 2.54);
    return 0;
}
