#include<stdio.h>
#include<conio.h>
int main()
{
    int numbers[10][10][10];
    int sum=0;
    for (int i=0;i<2;i++)
{
    for (int j=0;j<3;j++)
{
    for (int k=0;k<4;k++)
{
    sum += numbers[i][j][k];
}
    printf("sum = %d\n",sum);
    getch();
}
}
}
