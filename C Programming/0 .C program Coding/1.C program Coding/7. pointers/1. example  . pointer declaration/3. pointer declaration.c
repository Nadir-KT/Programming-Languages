#include<stdio.h>

int main()
{
	
	int i = 3 ;
	printf ( "\nAddress of i = %u", &i ) ;
	printf ( "\nValue of i = %d", i ) ;
	printf ( "\nValue of i = %d", *( &i ) ) ;
	
   int *p;
   int var = 10;
   p= &var;
   printf("\nValue of var is: %d", var);
   printf("\nAddress of var is: %u", p);
   return 0;
}

