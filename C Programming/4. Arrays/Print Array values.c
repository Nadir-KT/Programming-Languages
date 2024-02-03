#include<stdio.h>
#include<stdlib.h>
int main()
{int a[5];int i;
    printf("Enter the values of array\n");
    for(i=0;i<5;i++){printf("Enter the value of array element a[%d] = ",i);scanf("%d",&a[i]);}
    for(i=0;i<5;i++)printf("The array a[%d] is = %d\n",i,a[i]);
system("pause");}
