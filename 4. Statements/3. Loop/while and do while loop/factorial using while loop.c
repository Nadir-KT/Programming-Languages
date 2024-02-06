#include<stdio.h>
#include<stdlib.h>
int main(){int number,factorial=1;
    printf("Enter a number.\n");
    scanf("%d",&number);
    while (number>0){factorial=factorial*number;--number;}
    printf("Factorial of the entered number = %d\n",factorial);
system("pause");}
