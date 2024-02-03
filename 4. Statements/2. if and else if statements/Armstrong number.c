#include<stdio.h>
#include<stdlib.h>
int main(){int a,b,c,d,e,i,j,k,z;
    printf("Enter a 3 digit number : ");
    scanf("%d",&a);
    b=a%10;
    c=a/10;
    d=c%10;
    e=c/10;
    i=e*e*e;
    j=d*d*d;
    k=b*b*b;
    z=i+j+k;
    if(a==z)printf("%d is an Armstrong number\n",a); /// For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers
    else printf("%d is not an Armstrong number\n",a);
system("pause");}
