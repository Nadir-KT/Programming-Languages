#include<stdio.h>
main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    getch();
}
