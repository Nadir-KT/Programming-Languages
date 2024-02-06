// C code for function with argument but no return value
#include <stdio.h>
  
void function(int, int, char);
  
void main()
{
    function(1, 2, 'c');
}
  
void function(int a, int b, char c)
{
    printf("The function arguments values are %d, %d, %c", a,b,c);
}
