#include<stdio.h>
#include<stdlib.h>
int main(){int a,b,c,d,e,sum,average;
    printf("Enter marks for 5 subjects\n");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    sum=a+b+c+d+e;
    average=sum/5;
    printf("sum=%d average=%d\n",sum,average);
    system("pause");}
