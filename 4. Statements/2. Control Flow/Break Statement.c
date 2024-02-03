#include<stdio.h>
#include<conio.h>
int main()
{
    int p,q;
    while(p>0)
    {
        printf("%d\n",p);
        scanf("%d",&q);
        while(q>0)
        {
            printf("%d\n",p*q);
            if (q>100)
            break; //break from inner loop
            scanf("%d",&q);
        }
        if (q>100)
        break; //break from outer loop
        scanf("%d",&p);
    }
    getch();
}
