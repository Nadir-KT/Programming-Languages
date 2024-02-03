#include<stdio.h>
void main()
{
    int q,p,t,d,f;
    printf("Enter quantity of the item: ");
    scanf("%d",&q);
    printf("Enter price of the item: ");
    scanf("%d",&p);
    printf("Total Amount: %d/-\n",t=q*p);
    printf("Enter discount (%): "); // how to show % sign inside the program
    scanf("%d",&d);
    printf("Final Amount: %d/-",f=t-q*p*d/100); // bracket issue
}
