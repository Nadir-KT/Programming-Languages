#include <stdio.h>
void swapr(int *x, int *y)
{
    int t;
    t=*x;*x=*y;*y=t;
    printf("*x=%d\t *y=%d\n",*x,*y);
}
int main()
{
    int a=10,b=2;
    swapr(&a,&b);
    printf("a=%d b=%d\n",a,b);
    return 0;
}
