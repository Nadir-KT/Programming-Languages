/******************************************************************************

https://www.tutorialspoint.com/cprogramming/c_function_pointers.htm
https://www.geeksforgeeks.org/function-pointer-in-c/
https://www.geeksforgeeks.org/dereference-pointer-in-c/
https://www.scaler.com/topics/c-dereference-pointer/

*******************************************************************************/
#include <stdio.h>

int add (int a, int b){
    return a+b;
}

int sub (int a, int b){
    return a-b;
}

int main()
{
    int (*ptrfunc) (int, int);
    ptrfunc = add;
    int x = ptrfunc(10,12);
    ptrfunc = sub;
    int y =  ptrfunc(10,12);
    printf("%d %d",x,y);

    return 0;
}