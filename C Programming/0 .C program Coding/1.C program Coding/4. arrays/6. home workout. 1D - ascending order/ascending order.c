#include<stdio.h>
#include<conio.h>
void main()
{
int a[5],i,j,t;

printf("Enter 5 nos.\n\n");
for (i=0;i<5;i++)
scanf("%d",&a[i]);
for (i=0;i<5;i++)
{
for(j=i+1;j<5;j++)
{
if(a[i]>a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
printf("Ascending Order is:");
for(j=0;j<5;j++)
printf("\n%d",a[j]);
getch();}
