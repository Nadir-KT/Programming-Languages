#include <stdio.h>
int main()
{
    int avg = 0;
    int sum =0;
    int x=0;
    int num[20];
    for (x=0; x<=8;x++)
    {
        printf("enter the integer number %d\n", x);
        scanf("%d", &num[x]);
    }
    for (x=0; x<=8;x++)
    {
        sum = sum+num[x];
    }

    avg = sum/8;
    printf("%d", avg);
    return 0;
}
