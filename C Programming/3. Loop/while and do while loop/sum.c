#include <stdio.h>
#include<stdlib.h>
int main(){int sum=0,num;
do{printf("Enter a number\n");scanf("%d",&num);sum+=num;} //sum=sum+num
while(num!=0);printf("sum=%d\n",sum);
system("pause");}
