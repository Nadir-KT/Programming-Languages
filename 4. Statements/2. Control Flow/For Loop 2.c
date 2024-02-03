#include<stdio.h>
#include<conio.h>
int main()
{
    unsigned long long sum = 0LL;
    unsigned int count = 0;
    printf("Enter the number of integers you want to sum : ");
    scanf("%u",&count);
    for (unsigned int i=1;i<=count;++i)
    {
        printf("Inside loop %d\n",i);
        sum+=i;
    }
    printf("Total of the first %u numbers is %llu",count,sum);
    getch();
}
