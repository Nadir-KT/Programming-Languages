#include<stdio.h>
main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=n;i>=0;i--)
    {
        for(j=i;j>=0;j--)
        {
            printf("*");
        }
        printf("\n");
    }
    getch();
}
