#include <stdio.h>
int main()
{
    int i=10;
    int *j;
    j=&i;
    printf("%d\n",*j);
    return 0;
}
