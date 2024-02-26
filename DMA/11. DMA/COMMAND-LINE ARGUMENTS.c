#include<stdio.h>
int main(int argc,char *argv[])
{
    int i;
    char *c;
    for(i=1;i<argc;i++)
    {
        c=argv[i];
        printf("\n enterd strings are::%s",c);
    }
}
