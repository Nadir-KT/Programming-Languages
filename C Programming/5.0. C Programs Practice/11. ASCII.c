#include <stdio.h>
#include<conio.h>
int main()
{
    char c;
    printf("Enter a character to find its ASCII value : ");
    scanf("%c",&c);
    printf("ASCII value of character %c is %d\n",c,c);
    int n;
    printf("Enter a number to find its ASCII value : ");
    scanf("%d", &n);
    printf("Character corresponding to ASCII value %d is %c\n", n, n);
    getch();
}
