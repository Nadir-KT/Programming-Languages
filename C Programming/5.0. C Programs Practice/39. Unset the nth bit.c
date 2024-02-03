/*C program to get nth bit of a number

Write a C program to input any number from user and check whether nth bit of the given number is set (1) or not (0). How to check whether nth bit of a given number is set or unset using bitwise operator in C programming. C program to get the status of nth bit of a number.

Logic to get nth bit of a number

    Input number from user. Store it in some variable say j.
    Input the bit position from user. Store it in some variable say n.
    To get the nth bit of j right shift j, n times. Then perform bitwise AND with 1 i.e. bitStatus = (j >>) & 1;. */

#include <stdio.h>

int main()
{
    int j, n, bitStatus;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &j);

    /* Input bit position you want to check */
    printf("Enter nth bit to check (0-31): ");
    scanf("%d", &n);

    /* Right shift j, n times and perform bitwise AND with 1 */
    bitStatus = (j >> n) & 1;

    printf("The %d bit is set to %d", n, bitStatus);

    return 0;
}
