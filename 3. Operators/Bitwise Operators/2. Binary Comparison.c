#include <stdio.h>
int a=3;
int main()
{
    if((a&0b100)==4)//3rd bit is set
    printf("set");

    return 0;
}