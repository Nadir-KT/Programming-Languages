#include <stdio.h>
void main()
{
    char name[20];
    printf("\n enter string::");
    scanf("%[^\n]s",name);
    printf("%s\n",name);
}
