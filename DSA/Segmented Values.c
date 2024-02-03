/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int o=987654, o1, o2, o3, o4, o5, o6;
int main()
{
    o1=o/100000;
    o2=(o%100000)/10000;
    o3=((o%100000)%10000)/1000;
    o4=(((o%100000)%10000)%1000)/100;
    o5=((((o%100000)%10000)%1000)%100)/10;
    o6=((((o%100000)%10000)%1000)%100)%10;
    printf("%d", o1);
    printf("\n");
    printf("%d", o2);
    printf("\n");
    printf("%d", o3);
    printf("\n");
    printf("%d", o4);
    printf("\n");
    printf("%d", o5);
    printf("\n");
    printf("%d", o6);
    return 0;
}
