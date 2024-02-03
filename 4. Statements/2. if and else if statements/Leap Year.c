#include<stdio.h>
#include<stdlib.h>
int main(){int n;
    printf("Enter the year\n");
    scanf("%d",&n);
    if(n%4==0)
    printf("Entered year is a leap year\n");
    else
    printf("Entered year is not a leap year\n");
system("pause");}
