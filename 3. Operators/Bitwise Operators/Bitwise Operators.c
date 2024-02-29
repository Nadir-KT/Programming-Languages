#include<stdio.h>
#include<conio.h>
int main()
{
    unsigned int a=60; // 0011 1100
    unsigned int b=13; // 0000 1101
    unsigned int c=0;
    printf("A,B = %d,%d\n",a,b);
    c=a&b; //AND 0000 1100 = 12
    printf("AND & = %d\n",c);
    c=a|b; //OR 0011 1101 = 61
    printf("OR | = %d\n",c);
    c=a^b; //XOR 0011 0001 = 49
    printf("XOR ^ = %d\n",c);
    c=~a; // Flipping Bits 1100 0011
    printf("Flip ~A = %d\n",c);
    c=a<<2; // Right Shift 1111 0000 = 240
    printf("Right Shift A<<2 = %d\n",c);
    c=a>>2; // Left Shift 0000 1111 = 15
    printf("Left Shift A>>2 = %d\n",c);
    c=a>>3; // Left Shift
    printf("Left Shift A>>3 = %d\n",c);
	a = 00010000;
	b = 2;
	//a << b = 01000000 
	printf("Right Shift A<<B = %x\n",a << b);
	//a >> b = 00000100
	printf("Left Shift A>>B = %x\n",a >> b);
    getch();
}