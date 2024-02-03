#include<stdio.h>
#include<conio.h>
int main()
{
    int count,sum;
    for(int i=1;i<=count;i++)
    {
        sum =0; //Initialize sum for the inner loop
        for(int j=1;j<=i;j++) //Calculate sum of integers from 1 to i
        sum+=j;
        printf("%d\t%d\n",i,sum); //Output sum of 1 to i
    }
    getch();
}
