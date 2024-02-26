// C code for function with no arguments but have return value
#include <stdio.h>

int function(void);
//int value;
void main(void)
{
  int value = function(); // function call
  printf ("The function return value is %d", value);
}

int function(void)
{
  int ret = 2;
  return ret; //The return statement returns a value to where the function was called.
}
