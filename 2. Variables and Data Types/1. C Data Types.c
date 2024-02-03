#include<stdio.h>
int main(void)
{
    // Create variables
    int items = -50;;             // Integer (whole number)
    float myFloatNum = 5.99;   // Floating point number
    char myLetter = 'D';       // Character
    double myDoubleNum = 19.99;
    float cost_per_item = 9.99;
    float total_cost = items * cost_per_item;
    char currency = '$';
    // Print variables
    printf("Number of items: %d\n", items);
    printf("%lf", myDoubleNum); // Outputs 19.990000
    printf("%c\n", myLetter);
    printf("%f\n", myFloatNum);   // Outputs 3.500000 // Default will show 6 digits after the decimal point
    printf("%.1f\n", myFloatNum); // Only show 1 digit
    printf("%.2f\n", myFloatNum); // Only show 2 digits
    printf("%.4f\n", myFloatNum);   // Only show 4 digits
    printf("Number of items: %d\n", items);
    printf("Cost per item: %.2f %c\n", cost_per_item, currency);
    printf("Total cost = %.2f %c\n", total_cost, currency);
    // C Type Conversion
    int num1 = 5;
    int num2 = 2;
    float sum = (float) num1 / num2;
    printf("%f", sum); // 2.500000
    // When you declare a constant variable, it must be assigned with a value
    const int myNum = 15;  // C Constants (myNum will always be 15)
	return 0;
}