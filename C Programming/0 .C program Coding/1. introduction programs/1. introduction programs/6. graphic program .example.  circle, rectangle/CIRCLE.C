#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
 int at=DETECT, am;
initgraph(&at, &am,"C:\\tc\\bgi");
setcolor(getmaxcolor());
   circle(50, 50, 20);
   getch();
   closegraph();
   return 0;
}