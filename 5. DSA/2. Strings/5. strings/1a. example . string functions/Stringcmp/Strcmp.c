#include<stdio.h>
#include<string.h>
 
main()
{
   char a[100], b[100];
   int s;
 
   printf("Enter the first string\n");
   gets(a);
 
   printf("Enter the second string\n");
   gets(b);

   s=strcmp(a,b);
   printf("\n%d",s);

   if( s == 0 )
      printf("Entered strings are equal.\n");
   else
      printf("Entered strings are not equal.\n");
 
   getch();
}
