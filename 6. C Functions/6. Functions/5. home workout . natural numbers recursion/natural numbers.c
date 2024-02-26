#include<stdio.h>
#include<stdlib.h>
int naturaln(int);
int main()
{
    int d,e;
    d=25;
    e=naturaln(d);
    printf("The sum of the first %d digits is %d\n",d,e);
    system("pause");
    }
int naturaln(int x)
{
    int a;
    if(x==1)return(1);
    else{a=x+naturaln(x-1);return(a);}
    }
