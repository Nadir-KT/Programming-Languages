#include<stdio.h>
#include<stdlib.h>
int main(){int num,sum,a,b,c,d,e,f,g,h;
    printf("enter a five digit number : ");
    scanf("%d",&num);
    a=num%10;
    b=num/10;
    c=b%10;
    d=b/10;
    e=d%10;
    f=d/10;
    g=f%10;
    h=f/10;
    sum=a*10000+c*1000+e*100+g*10+h;
    printf("the reverse of the number is %d\n",sum);
    if(num==sum)
    printf("both the numbers are same");
    else
    printf("the numbers are not same");
system("pause");}

