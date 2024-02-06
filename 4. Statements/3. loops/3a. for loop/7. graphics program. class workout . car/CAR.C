#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
int main(){int i;
 int at=DETECT, am;
 initgraph(&at, &am,"C:\\tc\\bgi");
 line(50,50,100,50);
 line(100,50,150,30);
 line(150,30,250,30);
 line(250,30,300,50);
 line(300,50,350,50);
 line(50,50,50,100);
 line(350,50,350,100);
 line(50,100,100,100);
 line(350,100,300,100);
 arc(109,100,0,180,10);
 line(120,100,200,100);
 line(200,100,250,100);
 arc(260,100,0,180,10);
 line(269,100,350,100);
 circle(109,105,8);
 circle(260,105,8);
 setcolor(10);
getch();
closegraph();}

