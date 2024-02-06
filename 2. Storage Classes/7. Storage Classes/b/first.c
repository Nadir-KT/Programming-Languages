#include<stdio.h>
int result; // Data Definition
int add(int x,int y) // Function Definition
{
    result = x+y;
}
int disp()
{
    printf("\n Result in first file : %d\n",result);
}
