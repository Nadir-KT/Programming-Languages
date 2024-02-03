#include<stdio.h>
int main()
{
char name[15]="Vikramadithya";
int i=0;
while(name[i])
{
printf("%c",name[i]);
i=i+3;
}
return 0;
}
