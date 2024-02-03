#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
int main()
{
int i;
 int at=DETECT, am;
 initgraph(&at, &am,"C:\\tc\\bgi");
 for(i=0;i<=100;i++)
 {
 line(50+i,50,100+i,50);
 line(100+i,50,150+i,30);
 line(150+i,30,250+i,30);
 line(250+i,30,300+i,50);
 line(300+i,50,350+i,50);
 line(50+i,50,50+i,100);
 line(350+i,50,350+i,100);
 line(50+i,100,100+i,100);
 line(350+i,100,300+i,100);
 arc(109+i,100,0,180,10);
 line(120+i,100,200+i,100);
 line(200+i,100,250+i,100);
 arc(260+i,100,0,180,10);
 line(269+i,100,350+i,100);
 circle(109+i,105,8);
 circle(260+i,105,8);
   setcolor(10);
 delay(50);
 cleardevice();

 }
	  getch();
       closegraph();
 }

