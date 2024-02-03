#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){char str[50];
    int vowels=0,i=0;
    printf("\n\n\t ENTER A STRING: ");
    gets(str);
    while(str[i] != '0')
        {if(str[i]=='A'||str[i]=='a'||str[i]=='E'||str[i]=='e'||str[i]=='I'||
            str[i]=='i'||str[i]=='O'||str[i]=='o'||str[i]=='U'||str[i]=='u')
        vowels++;i++;}
    printf("\n\n\t THE TOTAL NUMBER OF VOWELS IS: %d", vowels);
system("pause");}
