#include<stdio.h>
#include<conio.h>
int main(int cnt, char *v[])
{
    int a = cnt;
    char *b = v[0];
    char *c = v[1];
    printf("Argument Count : %d\n", a);
    printf("Argument Vector0 : %s\n", b);
    printf("Argument Vector1 : %s\n", c);
    getch();
}
