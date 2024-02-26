#include<stdio.h>

struct foo
{
char c;
long l;
char *p;
};

union bar
{
char c;
long l;
char *p;
};

int main(int argc,char *argv[])
{
struct foo myfoo;
union bar mybar;

myfoo.c = 1;
myfoo.l = 2L;
myfoo.p = "This is myfoo";

mybar.c = 1;
mybar.l = 2L;
mybar.p = "This is mybar";

printf("myfoo: %d %ld %s\n",myfoo.c,myfoo.l,myfoo.p);
printf("mybar: %d %ld %s\n",mybar.c,mybar.l,mybar.p);

mybar.c = 1;
printf("mybar.c: %d \n",mybar.c);

mybar.l = 2L;
printf("mybar.l:  %ld \n",mybar.l);

mybar.p = "This is mybar";
printf("mybar.p: %s\n",mybar.p);

getch();
}
