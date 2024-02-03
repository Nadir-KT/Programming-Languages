#include<stdio.h>
void fun()
{
    printf("\n we are in function");
}
void main()
{
    void (*fun_ptr)();
    fun_ptr=fun;
    printf("\n we are in main");
    (*fun_ptr)();
    printf("\n");
}
