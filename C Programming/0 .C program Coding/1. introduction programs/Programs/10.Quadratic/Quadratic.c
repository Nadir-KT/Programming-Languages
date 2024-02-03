#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){float a,b,c;
float desc,root1,root2;
printf("Enter the Values of a : ");
scanf("%f",&a);
printf("Enter the Values of b : ");
scanf("%f",&b);
printf("Enter the Values of c : ");
scanf("%f",&c);
desc = sqrt(b*b-4*a*c);
root1 = (-b + desc)/(2.0*a);
root2 = (-b - desc)/(2.0*a);
printf("First Root : %f",root1);
printf("Second Root : %f",root2);
getch();}
