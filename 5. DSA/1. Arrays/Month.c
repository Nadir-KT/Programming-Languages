#include<stdio.h>
#include<conio.h>
#define MONTHS 12
int main()
{
    int days [MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    for (index=0;index<MONTHS;index++)
    printf("Month %d has %2d days.\n",index+1,days[index]);
    getch();
}
