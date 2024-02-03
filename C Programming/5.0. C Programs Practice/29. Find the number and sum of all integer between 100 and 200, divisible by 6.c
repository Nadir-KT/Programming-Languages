#include<stdio.h>
int main()
{
    int m=100,n=200,sum;
    for(;m<=n;m++)
    {
        if(m%6==0)
			printf("%d\n",m);
			 sum=sum+m;
    }
    printf("\n Sum of all no between 100 and 200 ");
    printf("which is divisible by 6 is :: %d",sum);
}
