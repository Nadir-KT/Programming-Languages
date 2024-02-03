#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
 main()
 {
    int i=0;
int at=DETECT, am;
initgraph(&at, &am,"C:\\tc\\bgi");
while(!kbhit())
{
if(i<500)
{
for(i=0;i<500;i++)
{
circle(200,i,20);

delay(2);
cleardevice();
} }
else
{
for(i=500;i>0;i--)
{
circle(200,i,20);
  delay(2);
cleardevice();
}}}
getch();
closegraph();
}