#include <stdio.h>
#include <conio.h>
void swap(int *d1 , int *d2)
{
int temp;
temp=*d1;
*d1=*d2;
*d2=temp;
}
main()
{
int a,b;
printf("Enter number a:");
scanf("%d", &a);
printf("\nEnter number b:");
scanf("%d", &b);
swap(&a,&b);
printf("\na contain %d",a);
printf("\nb contain %d",b);
getch();
}
