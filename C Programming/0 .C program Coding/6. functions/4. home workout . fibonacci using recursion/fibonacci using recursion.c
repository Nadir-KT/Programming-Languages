#include<stdio.h>
#include<stdlib.h>
void printFibonacci(int);
int main()
{
    int n=0;
    printf("Enter the range of the Fibonacci series : ");
    scanf("%d",&n);
    printf("Fibonacci Series : ");
    printf("%d %d ",0,1);
    printFibonacci(n);
    printf("\n");
    system("pause");
}
void printFibonacci(int n)
{
    static long int first=0,second=1,sum;
    if(n>0)
    {
        sum = first + second;
        first = second;
        second = sum;
        printf("%ld ",sum);
        printFibonacci(n-1);
    }
}
