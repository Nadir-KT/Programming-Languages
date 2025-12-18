/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <stdio.h>

void interchange(int *a, int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

int main()
{
    int a = 12;
    int b = 10;
    interchange(&a,&b);
    printf("%d %d",a,b);

    return 0;
}
