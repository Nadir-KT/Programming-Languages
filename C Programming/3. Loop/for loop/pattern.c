#include<stdio.h>
#include<stdlib.h>
int main(){int row=0,i=0,j=0,space=0;
    printf("Enter number of rows\n");
    scanf("%d",&row);
    space=row;
    for(i=1;i<=row;i++){for(j=1;j<space;j++)printf(" ");for(j=1;j<=i;j++){printf("*");}printf("\n");space--;}
system("pause");}

