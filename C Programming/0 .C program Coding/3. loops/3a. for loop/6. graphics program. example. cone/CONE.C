#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
int main(void){
    int i,j;
    int at=DETECT, am;
    initgraph(&at,&am,"C:\\tc\\bgi");
    for(j=0;j<=5;j++)
        {
            for(i=0;i<=20;i++)
            {
                circle(50+i, 50+i, 20+i); setcolor(random(15));delay(30);
    }
    cleardevice();
    }
   getch();
   closegraph();
   return 0;}
