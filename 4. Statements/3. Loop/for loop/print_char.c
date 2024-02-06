#include<stdio.h>
#include<stdlib.h>
int main(){
    char c;
    printf("ASCII table\n");
    for(c=30;c<=126;c++)
    printf("ASCII code %d is character %c\n",c,c);
    printf("ASCII code 48 to 57 is : ");
    for(c=48;c<=57;c++)
        printf("%c ",c);
        printf("\nASCII code 65 to 90 is upper case characters : ");
    for(c=65;c<=90;c++)
        printf("%c ",c);
        printf("\nASCII code 97 to 122 is lower case characters : ");
    for(c=97;c<=122;c++)
        printf("%c ",c);
        printf("\n");
system("pause");}
