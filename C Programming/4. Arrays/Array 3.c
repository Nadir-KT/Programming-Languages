main()
{
int a[10];
int i=0;
for(;;)
    {
        if(!(i<5))
        {
            break;
        }
        scanf("%d",&a[i]);
        printf("number of index %d is equal to %d\n",i,a[i]);
        i++;
    }
getch();
}
