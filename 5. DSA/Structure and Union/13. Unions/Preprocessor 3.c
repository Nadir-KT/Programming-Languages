#include<stdio.h>
#define ISM

void main()
{
    #ifdef ISM
    {
        printf("\n ifdef");
    }
    #else
    {
        printf("\n else");
    }
    #endif
}
