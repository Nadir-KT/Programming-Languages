#include<stdio.h>
#include<stdlib.h>
int main()
{int i=0,j;
    do{j=0;do{printf("%d",j);j++;}while(j<=i);i++;printf("\n");}while(i<=5);
system("pause");}
