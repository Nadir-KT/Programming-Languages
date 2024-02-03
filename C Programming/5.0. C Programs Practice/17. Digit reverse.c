#include<stdio.h>
#include<stdlib.h>
int main(){int num,sum,a,b;
    printf("enter a two digit number : ");
    scanf("%d",&num);
    a=num%10;
    b=num/10;
    sum=a*10+b;
    printf("the reverse of the number is %d\n",sum);
    if(num==sum)
    printf("both the numbers are same");
    else
    printf("the numbers are not same\n");
system("pause");}
