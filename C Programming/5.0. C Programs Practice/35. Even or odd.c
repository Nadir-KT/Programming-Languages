#include<stdio.h>
int main()
{
   int n;
   // int mask=0x1;
   printf("Enter an integer\n");
   scanf("%d",&n);
   // if((n&mask)==0)
   if ( n & 1 == 1 )  // Operator == Checks if the values of two operands are equal or not. If yes, then the condition becomes true.
      printf("Odd\n");
   else
      printf("Even\n");
   return 0;
}
