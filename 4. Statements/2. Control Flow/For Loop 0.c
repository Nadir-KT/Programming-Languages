#include<stdio.h>
#include<conio.h>
int main()
{
    for (int i=1,j=2;i<=10;++i,j=j+2)
    printf("%5d",i*j);
    getch();
}
