#include <stdio.h>
void add(int [][2]);
void main()
{
    int a[2][2] = {{1,2},{3,4}};
    add(a);
}
void add(int b[][2])
{
    int i,sum,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            sum += b[i][j];
        }
    }
    printf("%d\n",sum);
}
