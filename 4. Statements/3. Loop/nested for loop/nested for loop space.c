#include<stdio.h>
main()
{
    int i,j,n,space,count=1;
    printf("Enter number of rows\n");
    scanf("%d",&n);
    space=n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<space;j++)
        printf(" ");
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
        space--;
        count=1;
    }
    getch();
}
