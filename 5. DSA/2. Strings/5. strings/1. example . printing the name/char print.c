#include<stdio.h>
#include<stdlib.h>
int main(){char name[]="Software Engineering";
int i=0;
while(i<=8){printf("%c",name[i]);i++;} // change printf("%c",name[i]) to puts(name)
printf("\n");
puts(name);
system("pause");}
