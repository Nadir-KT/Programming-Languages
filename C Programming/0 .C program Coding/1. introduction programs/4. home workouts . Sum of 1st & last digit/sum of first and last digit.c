#include<stdio.h>

main ()

{

int number, last_digit, first_digit, total;

printf (" Enter the number a 4 digit number: ");

scanf ("%d", &number);



last_digit = number % 10;

total = last_digit;



first_digit = (number / 1000) % 10;

total = total + first_digit;



printf ("The total of the first and the last digit of the entered number is: %d", total);


getch();

}
