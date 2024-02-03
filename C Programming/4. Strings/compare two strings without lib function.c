#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s1[50], s2[50];
    puts("Enter first string");
    gets(s1);
    puts("Enter second string");
    gets(s2);
    printf("First String : %s\n",s1);
    printf("Second string : %s\n",s2);
    if(strcmp(s1,s2)==0){printf("Same string or strings are equal\n");}
    else if(strcmp(s1,s2)<0){printf("First string is smaller\n");}
    else if(strcmp(s1,s2)>0){printf("Second string is smaller\n");}
system("pause");}

