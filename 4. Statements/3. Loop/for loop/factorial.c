#include<stdio.h>
#include<stdlib.h>
int main(){unsigned int number=0,n=0,factorial=1;
    printf("Enter a number : ");
    scanf("%d",&number);
    for(n=1;n<=number;n++){factorial=n*factorial;}//while(n>0)
    printf("Factorial of the entered number is %d\n",factorial);
system("pause");}
