#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){char a[100],b[100];int s;
    puts("Enter the first string");
    gets(a);
    puts("Enter the second string");
    gets(b);
    s=strcmp(a,b);
    printf("strcmp = %d\n",s);
    if(s==0)
        puts("Entered strings are equal.");
    else
       puts("Entered strings are not equal.");
system("pause");}
