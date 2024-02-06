#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void){int i;
int at=DETECT, am;
initgraph(&at, &am,"C:\\tc\\bgi");
for(i=0;i<=500;i++){putpixel(random(500),random(500),random(15));delay(5);}
getch();
closegraph();
return 0;}
