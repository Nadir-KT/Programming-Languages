#include<stdio.h>
#include<stdlib.h>
int main(){double w=0,h=0,aor,por,radius=0,aoc,coc;
    printf ("Enter the Width and Height of the Rectangle : ");
    scanf("%lf%lf", &w,&h);
    printf("Enter the Radius of the Circle: ");
    scanf("%lf", &radius);
    aor=w*h;
    por=2*(w+h);
    aoc=radius*radius*3.14;
    coc=radius*2*3.14;
    printf("Area of the rectangle : %lf\n", aor);
    printf("Perimeter of the rectangle : %lf\n", por);
    printf("Area of the circle with radius %lf is : %lf\n",radius,aoc);
    printf("Circumference of the same circle is : %lf\n",coc);
system("pause");}
