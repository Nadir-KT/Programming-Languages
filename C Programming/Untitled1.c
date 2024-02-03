#include <stdio.h>
void print(char *d)
{
	//while(*d!='\0')
	while(*d)
{
printf("%c",*d);
d++;
}
}
void decrement(int a)
{
	while(a--);
}
void main()
{
	while(1)
{
    print("Hello\n");
    //printf("Hello World 1\n");
    //decrement(9999);
    //printf("Hello World 2\n");
    //decrement(9999);
    }
}
