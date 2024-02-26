#include<stdio.h>
#include<string.h>
 
main()
{
   char a[100];
   int length;
 
   printf("Enter a string to calculate it's length\n");
   gets(a);
 
   //length = strlen(a);
 
   printf("Length of entered string is = %d\n",strlen(a));
 
  getch();
}
