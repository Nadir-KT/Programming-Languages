main()
{
    int a[10];
    int j=0;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
        printf("number of index %d is equal to %d\n",i,a[i]);
        for(;j<5;j++)
            {
                printf("waiting for j to be 5\n");
            }
    }
    getch();
}
