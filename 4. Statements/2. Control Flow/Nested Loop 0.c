#include<stdio.h>
#include<conio.h>
int main()
{
    int count,sum,j;
    for(int i=1;i<=count;i++)
    {
        sum =0; //Initialize sum for the inner loop
        j=1; //Initialize integer to be added
        printf("\n1");
        while(j<i) //Calculate sum of integers from 1 to i
        {
            sum+=j++;
            printf("+%d",j); //Output +j- on the same line
        }
        printf("=%d\n",sum); //Output = sum
    }
    getch();
}
