#include<stdio.h>
#include<conio.h>
int main()
{
    int a=90;
    int b=95;
    if(a>b)
    printf("Jackpot!\n");
    if(a<b)
    {
        a++;
        printf("You win\n");
    }
    int n,v;
    printf("Enter a number\n");
    scanf("%d",&n);
    v=n%2;
    if(v==0)
    printf("Even");
    else
    printf("Odd");
    getch();
}
