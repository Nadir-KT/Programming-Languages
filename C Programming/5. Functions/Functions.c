#include <stdio.h>
#include<conio.h>
int multiply(int a,int b){
//int result=a*b;
//return result;
return a*b;}
int Max(int a,int b){if (a>b){return a;}else{return b;}}
void increment(int *a){(*a)++;}
int factorial(int a){//if a=4 the factorial=4*3*2*1
    if(a==1){return a;}else{return a*factorial(a-1);}}
void Void_Hello(){printf("Void Command");}
int main()
{
    int num=5;
    int temp=multiply(3,20);
    int temp2=multiply(5,num);
    printf(" in temp is now %i & temp2 is %i \n",temp,temp2);
    printf("Max(10,5) is %d\n",Max(10,5));
    int b=50;
    increment(&b);
    printf("increment b = %i\n",b);
    printf("Factorial of 4 = %i\n",factorial(4));
    Void_Hello();
    getch();
}
