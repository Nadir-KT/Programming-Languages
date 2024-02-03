#include <stdio.h>
void main()
{
    int i[5]= {1,2,3,4,5},*j;
    j=&i[0];
    printf("%d\n",*j);
    j=j+1;
    printf("%d\n",*j);
    j=j+3;
    printf("%d\n",*j);
}
