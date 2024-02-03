#include <stdio.h>
void main()
{
    int i[5]= {10,20,30,40,50},*j,*k;
    j=&i[0];
    k=&i[4];
    printf("%d\n",*j);
    printf("%d\n",*k);
    printf("%d\t%d\n",&k,&j);
    printf("%d\n",k-j);
    printf("%d\n",*k-*j);
}
