#include<stdio.h>
#include<conio.h>
int main()
{
    char a[0];
    int n,v;
    printf("Do you want to continue (Y/N) : ");
    scanf("%c",&a);
    if(!strcmp(a,"N"))
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
