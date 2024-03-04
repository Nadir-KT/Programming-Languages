/******************************************************************************
C Program to Remove Characters in Second String which are present in First String
*******************************************************************************/
#include <stdio.h>
#include <string.h>
char string1[] = "computer";
char string2[] = "cat";
int main()
{
    char string3[5]={0};
    for(int i=0;i<strlen(string2);i++) {
        for(int j=0;j<strlen(string1);j++) {
            if(string2[i]==string1[j]) {
                for(int k=0;k<(strlen(string1)-j);k++) {
                    string1[j+k]=string1[j+k+1];
                }
            }
        }
    }
printf("%s",string1);
}