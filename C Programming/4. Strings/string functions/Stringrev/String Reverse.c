#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){char s[100];
    printf("Enter a string to reverse\n");
    gets(s);
    strrev(s);
    printf("Reverse of entered string is \n%s\n",s);
system("pause");}
