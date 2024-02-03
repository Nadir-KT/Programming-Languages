#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,b,c;
    printf("Enter the value of A & B : ");
    scanf("%d%d",&a,&b);
    a=a+b;
    printf("A = %d\n",a);
    b=a-b;
    printf("B = %d\n",b);
    a=a-b;
    printf("A = %d\n",a);
    printf("After swapping the values are : A = %d B = %d\n",a,b);
system("pause");}
