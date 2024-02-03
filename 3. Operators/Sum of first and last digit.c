#include<stdio.h>
#include<stdlib.h>
int main(){int number, last_digit, first_digit, total;
    printf ("Enter a 5 digit number : ");
    scanf ("%d", &number);
    last_digit = number % 10; //Modulo (%)
    total = last_digit;
    first_digit = (number / 10000); //Division
    total = total + first_digit;
    printf ("The total of the first and the last digit of the entered number is : %d\n", total);
system("pause");}
