#include<stdio.h>
main()
{
    int p,q,t,f;
    printf("Enter price: ");
    scanf("%d",&p);
    printf("Enter quantity: ");
    scanf("%d",&q);
    t=p*q;
    if(t>1000)
        {
        f=t*.85;
        printf("Discount = 15\n");
        printf("Final payment = %d",f);
        }
    else
        {
        f=t*.90;
        printf("Discount = 10\n");
        printf("Final payment = %d",f);
        }
}
