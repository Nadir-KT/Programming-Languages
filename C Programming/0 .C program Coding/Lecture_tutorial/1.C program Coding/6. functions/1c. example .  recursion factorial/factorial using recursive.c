#include<stdio.h>
int fact(int);

main()
{
  int num,f;
  printf("\nEnter a number: ");
  scanf("%d",&num);
  f=fact(num);
  printf("\nFactorial of %d is: %d",num,f);
  getch();
}

int fact(int n)
{
   if(n==1)
       return 1;
   else
       return(n*fact(n-1));
 }
