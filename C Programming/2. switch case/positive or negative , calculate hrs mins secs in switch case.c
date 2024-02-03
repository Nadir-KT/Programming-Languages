#include<stdio.h>
#include<stdlib.h>
int main(){int c,h,m,s,n;
printf("Option 1 : Calculate seconds in hours & minutes\n");
printf("Option 2 : Check whether the number is positive or negative\n");
printf("Option 3 : Exit\n");
printf("Select an option number\n");
scanf("%d",&c);
char positive,negative;
switch(c)
{case 1:
    printf("Enter seconds\n");
    scanf("%d",&s);
    m=s/60;
    h=m/60;
    printf("hours=%d minutes=%d seconds=%d\n",h,m,s);
    break;
case 2:
    printf("Enter the number\n");
    scanf("%d",&n);
    if(n>0)printf("Positive\n");
    else if(n<0)printf("Negative\n");
    else printf("Zero\n");
    break;
case 3:
    exit(0);
default:
    printf("default\n");
    break;}
system("pause");}
