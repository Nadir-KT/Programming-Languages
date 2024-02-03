#include <stdio.h>
void display(int []);
void main()
{
    int a[5] = {1,2,3,4,5};
    display(a);
}
void display(int b[])
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%d\n",b[i]);
    }
}
