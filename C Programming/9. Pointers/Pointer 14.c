#include <stdio.h>
int main()
{
    char str1[25];
    char str2[25];
    printf("\nEnter first string ");
    scanf("%s",str1);
    printf("\nEnter second string ");
    scanf("%s",str2);
    if(strcmp(str1,str2)==0)
        printf("\nBoth are equal");
    else if(strcmp(str1,str2)>0)
        printf("\nFirst String is Greater than second String");
    else
        printf("\nFirst String is Less than second String");
}
