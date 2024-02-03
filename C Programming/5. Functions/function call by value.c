#include<stdio.h>
#include<stdlib.h>
int sum(int x,int y)
{
    int z;
    z=x+y;
    return z ;
    }
//int sum(int x,int y);
int main()
{
    int x,y,s;
    printf("Enter value of X & Y\n");
    scanf("%d%d",&x,&y);
    s=sum(x,y);
    printf("Sum of X & Y = %d\n",s);
    system("pause");
    }
//int sum(int x,int y)
//{
//    int z;
//    z=x+y;
//    return z ;
//    }
