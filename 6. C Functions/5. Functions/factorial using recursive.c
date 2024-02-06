#include<stdio.h>
#include<stdlib.h>
int fact(int n)
{
   if(n==1)
       return 1;
   else
       return(n*fact(n-1));
 }
//int fact(int);
int main()
{
  int num,f;
  printf("Enter a number : ");
  scanf("%d",&num);
  f=fact(num);
  printf("Factorial of %d is %d\n",num,f);
  system("pause");
}
//int fact(int n)
//{
//   if(n==1)
//       return 1;
//   else
//       return(n*fact(n-1));
// }
