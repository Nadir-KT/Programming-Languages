#include<stdio.h>
#include<stdlib.h>
int main(){int i=3;
	printf("Address of i = %u\n",&i);
	printf("Value of i = %d\n",i);
	printf("Value of i = %d\n",*(&i));
	int *p;
	int var=10;
	p=&var;
	printf("Value of var is: %d\n",var);
	printf("Address of var is: %u\n",p);
	system("pause");}

