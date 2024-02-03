#include<stdio.h>
#include<conio.h>
int main()
{
    int n=0;
    int s=0;
    printf("Enter the number of integers you want to sum : ");
    scanf("%d",&n);
    for (int i=1;i<=n;s+=i++)
    {
        printf("Inside loop %d\n",i);
    }
    printf("Total of the first %d numbers is %d",n,s);
    getch();
}
