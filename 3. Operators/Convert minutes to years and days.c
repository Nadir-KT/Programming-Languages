#include<stdio.h>
#include<conio.h>
int main()
{
    int m;
    double d=0.0,y=0.0;
    printf("Enter the number of minutes : ");
    scanf("%d",&m);
    d=(m/60.0)/24.0;
    y=m/(60.0*24.0*365.0);
    printf("%d hours is approximately %f days & %f years",m,d,y);
    getch();
}
