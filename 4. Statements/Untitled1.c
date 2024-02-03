#include<stdio.h>
int main()
{
    int a=0;
    switch(a)
    {
        default : printf("ism\n");
        case 1: a++;
        case 2: a++; break;
    }
    printf("%d\n",a);
}
