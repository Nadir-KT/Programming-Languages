#include<stdio.h>
#include<conio.h>
int main()
{
    int l=0;
    printf("Enter the number of inside loops  : ");
    scanf("%d",&l);
    for (int i=1;i<=l;i++)
        printf("Inside loop %d\n",i);
    getch();
}
