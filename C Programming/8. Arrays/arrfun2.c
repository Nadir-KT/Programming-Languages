#include <stdio.h>
void add(int []);
void main()
{
    int a[5] = {1,2,3,4,5};
    add(a);
}
void add(int b[])
{
    int i,sum;
    for(i=0;i<5;i++)
    {
        sum += b[i];
    }
    printf("%d\n",sum);
}
