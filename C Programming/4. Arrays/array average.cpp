#include<stdio.h>
#include<stdlib.h>
int main()
{int avg=0,sum=0,x=0,num[20];
    for(x=1;x<=9;x++){printf("Enter the integer number %d : ",x);scanf("%d",&num[x]);}
    for (x=1;x<=9;x++){sum+=num[x];} /// sum+=num[x] = sum=sum+num[x]
    avg=sum/8;
    printf("Sum = %d\n",sum);
    printf("Average = %d\n",avg);
system("pause");}
