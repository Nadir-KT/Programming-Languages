#include<stdio.h>
int main()
{
    int m,n;
    printf("Enter stating and ending number ");
    scanf("%d%d",&m,&n);
    for(;m<=n;m++)
    {
        if(m%2==0)
			printf("Even Number %d\n",m);
		else
			printf("Odd Number %d\n",m);
    }
}
