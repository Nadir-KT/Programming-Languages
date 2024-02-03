#include<stdio.h>
int *fun()
{
    int i=20;
    return (&i);
}
void main()
{
    int *p;
    p=fun();
    printf("\n address is::%u\t value is::%d",&p,*p);
}
