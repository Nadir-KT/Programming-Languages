#include<stdio.h>
main()
{
    char str[]="ismism";
    strcpy(str,str+3);
    printf("%s",str);
}
