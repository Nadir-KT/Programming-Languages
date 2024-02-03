#include<stdio.h>
#include<conio.h>
int main()
{
    char a;
    int b,n,v;
    printf("Do you want to continue (Y/N) : ");
    scanf("%c",&a);
    b=a;
    if(b==78)
    printf("Thank You");
    else
    printf("Enter a number\n");
    scanf("%d",&n);
    v=n%2;
    if(v==0)
    printf("Even");
    else
    printf("Odd");
    getch();
}
