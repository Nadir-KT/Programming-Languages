#include<stdio.h>
void main()
{
    enum year{Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    int i;
    for (i=Jan; i<=Dec; i++)
        printf("%d ", i);
}
