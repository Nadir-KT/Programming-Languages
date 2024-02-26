#include <stdio.h>
void main()
{
    int i[5]= {10,20,30,40,50},*p;
    p=&i[0];
    printf("%d\n",*(p+0));
    printf("%d\n",*(p+1));
    printf("%d\n",*(p+2));
    printf("%d\n",*(p+3));
    printf("%d\n",*(p+4));
}
