/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int a[10] = {};
struct struc {
    int b;
    int c;
} s1;
int func1 (int a, int b);
int func2 (int a, int b);
int main()
{
    unsigned int y = &a;
    printf("addr array %d\n",y);
    struct struc struc1;
    struc1.b=1;
    struc1.c=2;
    struct struc *struc2;
    struc2 = &struc1;
    printf("%d\n",struc2->b);
    int (*func) (int, int);
    func = func1;
    int x = func(1,3);
    printf("%d\n",x);
    return 0;
}

int func1 (int a, int b){
    return a+b;
}
int func2 (int a, int b){
    return a-b;
}