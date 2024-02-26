#include<stdio.h>
#include<conio.h>
struct z {int x; int y;};
struct z u(struct z a,struct z b) {struct z w; w.x=a.x+b.x; w.y=a.y+b.y; return w;};
int main(){
    struct z a;
    a.x = 3;
    a.y = 5;
    struct z b = {10,23};
    struct z *c = &a;
    c->x = 5;
    struct z d = u(a,b);
    printf("%d,%d\n",a.x,a.y);
    printf("%d,%d\n",b.x,b.y);
    printf("%d,%d\n",d.x,d.y);
    getch();}
