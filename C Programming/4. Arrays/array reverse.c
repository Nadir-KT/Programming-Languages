#include<stdio.h>
#include<stdlib.h>
int main(){int a[10],i,sum=0;
    printf("Enter the 5 values of array\n");
    for(i=0;i<5;i++)scanf("%d",&a[i]);
    for(i=0;i<5;i++)printf("a[%d]=%d\n",i,a[i]);
    for(i=0;i<5;i++)sum=a[i]+sum;
    printf("sum of the array = %d\n",sum);
    for(i=4;i>=0;i--)printf("b[%d]=%d\n",i,a[i]);
system("pause");}

