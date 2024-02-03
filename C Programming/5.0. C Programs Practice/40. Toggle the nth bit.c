/* C program to toggle or invert nth bit of a number

Write a C program to input any number from user and toggle or invert or flip nth bit of the given number using bitwise operator. How to toggle nth bit of a given number using bitwise operator in C programming. C program set nth bit of a given number if it is unset otherwise unset if it is set.

Logic to toggle nth bit of a number

Toggling bit means setting a bit in its complement state. Means if bit is currently set then change it to unset and vice versa.

To toggle a bit we will use bitwise XOR ^ operator. Bitwise XOR operator evaluates to 1 if corresponding bit of both operands are different otherwise evaluates to 0. We will use this ability of bitwise XOR operator to toggle a bit. For example - if Least Significant Bit of j is 1, then j ^ 1 will make LSB of j to 0. And if LSB of j is 0, then j ^ 1 will toggle LSB to 1.

    Input number and nth bit position to toggle from user. Store it in some variable say j and n.
    Left shift 1 to n times, i.e. 1 << n.
    Perform bitwise XOR with j and result evaluated above i.e. j ^ (1 << n);. */

#include <stdio.h>

int main()
{
    int j, n, newj;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &j);

    /* Input bit position you want to toggle */
    printf("Enter nth bit to toggle (0-31): ");
    scanf("%d", &n);

    /*
     * Left shifts 1, n times
     * then perform bitwise XOR with j
     */
    newj = j ^ (1 << n);

    printf("Bit toggled successfully.\n\n");
    printf("Number before toggling %d bit: %d (in decimal)\n", n, j);
    printf("Number after toggling %d bit: %d (in decimal)\n", n, newj);

    return 0;
}
