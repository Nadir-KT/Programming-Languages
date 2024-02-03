#include<stdio.h>
extern int result; // Declaration
void add(int,int);
void sub(int,int);
int main()
{
    int a=10,b=20;
    result=10;
    printf("before calling add %d\n",result);
    add(a,b);
    printf("\n Result = %d",result);
    sub(a,b);
    printf("\n Result = %d\n",result);
    disp();
}
