#include<stdio.h>
#include<conio.h>
int string_ln(char*);
int main()
{
  char str[20];
  int l;
  printf("Enter any string:\n");
  gets(str);
  l=string_ln(str);
  printf("The length of the given string %s is : %d",str,l);
  getch();
}
int string_ln(char*p)  
{
  int count=0;
  while(*p!=NULL)
  {
    count++;
    p++;
  }
  return count;
}
