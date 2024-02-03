#include<stdio.h>
#include<stdlib.h>
int main()
{int n,a,b,c,d,e,f,g,h,sum;
    printf("Enter a 5 digit number : ");
    scanf("%d",&n);
    a=n/10;               //division
    b=n%10;               //remainder
    c=a/10;
    d=a%10;
    e=c/10;
    f=c%10;
    g=e/10;
    h=e%10;
    sum=b+d+f+g+h;
    printf("Sum of the 5 digit number is : %d\n",sum);
system("pause");}
