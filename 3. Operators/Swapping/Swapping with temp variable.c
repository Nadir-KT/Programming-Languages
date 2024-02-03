#include<stdio.h>
#include<stdlib.h>
int main(){int a,b,c;
    printf("Enter the value of A & B : ");
    scanf("%d%d",&a,&b);
    c=a;
    a=b;
    b=c;
    printf("After swapping the values are : A = %d B = %d\n",a,b);
system("pause");}
