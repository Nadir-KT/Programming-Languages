#include<stdio.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Binary representation in reverse: ");
    for(n ; n>0; n=n/2)
    {
        printf("%d",n%2);
    }
    return 0;
}