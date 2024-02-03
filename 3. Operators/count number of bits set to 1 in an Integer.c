/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
	unsigned int n;
	printf("enter the integer\n");
	scanf("%d",&n);

	int count=0;

	while(n!=0){
		if(n & 1 == 1){ //if current bit 1
			count++;//increase count
		}
		n=n>>1;//right shift
	}

	printf("no of bits those are 1 ");
	printf("in its binary representation: %d\n",count);

	return 0;
}