#include <stdio.h>
void main()
{
    int a,b,c,d,*p[4];
    a=10;
    b=20;
    c=30;
    d=40;
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    p[3] = &d;
    printf("%d %d %d %d\n",*p[0],*p[1],*p[2],*p[3]);
}
