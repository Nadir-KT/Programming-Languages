#include<stdio.h>
#include<stdlib.h>
int main(){int n=0,c=0,k=0;
    printf("Enter number of rows\n");
    scanf("%d",&n);
    for(c=1;c<=n;c++){for(k=1;k<=c;k++)printf("%d",c);printf("%d\n",k);}
system("pause");}
