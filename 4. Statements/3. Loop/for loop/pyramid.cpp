#include <stdio.h>
#include<stdlib.h>
int main(){int row,c,n,space;
    printf("Enter the number of rows in pyramid of stars you wish to see ");
    scanf("%d",&n);
    space=n;
    for(row=1;row<=n;row++){for(c=1;c<=space;c++)printf(" ");space--;for(c=1;c<=row;c++)printf("*");printf("\n");}
system("pause");}

