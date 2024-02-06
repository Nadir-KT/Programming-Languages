#include<stdio.h>
#include<stdlib.h>
int main()
{int i=0,j;
    do{j=i;do{printf("%d",j);j++;}while(j<=5);i++;printf("\n");}while(i<=5);
system("pause");}
