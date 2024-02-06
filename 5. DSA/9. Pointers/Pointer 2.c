#include <stdio.h>
int main()
{
    int i=10, *j=&i, **k=&j;
    printf("\n i value is::%d",i);
    printf("\n i value address is::%p",&i);
    printf("\n j value is ::%d",*j);
    printf("\n j address is::%p",&j);
    printf("\n j holding address is::%p",j);
    printf("\n k value is::%d",**k);
    printf("\n k address is::%p",&k);
    printf("\n k holding address is::%p\n",k);
}
