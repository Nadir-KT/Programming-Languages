#include <stdio.h>
int main(void) // use of int main(void)
{
int p,c,m,b,e,s,per;
printf("Enter marks for Physics: ");
scanf("%d",&p);
printf("Enter marks for Chemistry: ");
scanf("%d",&c);
printf("Enter marks for Math: ");
scanf("%d",&m);
printf("Enter marks for Biology: ");
scanf("%d",&b);
printf("Enter marks for English: ");
scanf("%d",&e);
s=(p+c+m+b+e);
p=(s*100/500);
printf("Your total marks is %d\n",s);
printf("You got %d percentage",p);
}

