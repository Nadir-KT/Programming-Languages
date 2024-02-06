#include <stdio.h>
int main()
{
    int a[2][2] = {{10,20},{30,40}},i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\n",a[i][j]);
        }
    }
}
