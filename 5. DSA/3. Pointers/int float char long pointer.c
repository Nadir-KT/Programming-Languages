#include<stdio.h>
#include<stdlib.h>
int main(){int i=10;
    float f=1.5,*pc;
    long l=77777;
    char c='e';
    int *cp;
    cp=&c;
    printf("char=e %c %u\n",*cp,cp);
    cp=&i;
	printf("int=10 %i %u\n",*cp,cp);
	cp=&l;
    printf("long=77777 %ld %u\n",*cp,cp);
    pc=&f;
    printf("float=1.5 %f %u\n",*pc,pc);
system("pause");}
