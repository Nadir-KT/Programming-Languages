#include <stdio.h>
#include <string.h>
int main()
{
    char str_source[25]="ISM UNIV";
    char str_dest[25];
    char *result;
    printf("\n source string : %s",str_source);
    result = strcpy(str_dest,str_source); // Copies src to dest
    printf("\n Destination string : %s\n",str_dest);
    printf("\n Result string : %s\n",result);
    return 0;
}
