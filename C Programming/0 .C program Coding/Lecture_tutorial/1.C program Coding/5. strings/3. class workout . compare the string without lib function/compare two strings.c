#include<stdio.h>
#include<conio.h> 
#include<string.h>

int main()
{
  char str1[50], str2[50];
 
 
 printf("Enter first string : ");
 gets(str1);
 
 printf("Enter second string : ");
 gets(str2);
 

 printf("First String : %s\n",str1);
 printf("Second string : %s\n",str2);
 
 
 if(strcmp(str1,str2)==0)
 {
  printf("Same string or string are equal");
 }
 
 else if(strcmp(str1,str2)<0)
 {
  printf("First string is smaller ");
 }
 
 else if(strcmp(str1,str2)>0)
 {
  printf("Second string is smaller ");
 }
 
 getch(); 

 return 0;
}

