#include <stdio.h>
main()
{
    int a=10,b=5;
    a^=b^=a^=b;
    printf("a=%d,b=%d",a,b);
}
