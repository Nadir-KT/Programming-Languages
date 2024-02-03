#include<stdio.h>
#include<conio.h>
int main()
{
    int n,sign;
    printf("Please type in a number : ");
    scanf("%i",&n);
    if(n<0)
    sign = -1;
    else if (n==0)
    sign = 0;
    else
    sign = 1;
    printf("Sign = %i\n",sign);
    getch();
}
