#include<graphics.h>
#include<conio.h>

void main()
{
int at=DETECT, am;
 initgraph(&at, &am,"C:\\tc\\bgi");
 rectangle(50,50,150,150);
 floodfill(60,60,15);

 getch();
 closegraph();
 }




