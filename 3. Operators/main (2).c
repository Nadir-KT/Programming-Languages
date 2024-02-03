/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
 
int countSetBits(unsigned int n)
{
  unsigned int c; // the total bits set in n
  for (c = 0; n; n >>= 1)
  {
    c += n & 1;
  }
  return c;
}
 
int main(void)
{
  unsigned int n;
  printf("Enter a positive integer: ");
  scanf("%u", &n);
  printf("%d\n", countSetBits(n));
}