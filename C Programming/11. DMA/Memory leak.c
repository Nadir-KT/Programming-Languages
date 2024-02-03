#include<stdio.h>
#include<stdlib.h>
void main()
{
    char *c=(char *)malloc(10*sizeof(char));
    char *c1=(char *)malloc(10*sizeof(char));
    gets(c);
    gets(c1);
    printf("\n %s",c);
    printf("\n %s",c1);
    c1=c;
    printf("\n %s",c);
    printf("\n %s",c1);
    free(c);
    free(c1);
}
