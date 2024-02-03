#include <stdio.h>
int main(void)
{
int m1,m2,m3,m4,m5,sum,per;
printf("Enter marks for Math : ");
scanf("%d",&m1);
printf("\nEnter marks for Chemistry : ");
scanf("%d",&m2);
printf("\nEnter marks for Biology : ");
scanf("%d",&m3);
printf("\nEnter marks for Physics : ");
scanf("%d",&m4);
printf("\nEnter marks for English : ");
scanf("%d",&m5);
sum = (m1 + m2 + m3 + m4 + m5);
per = (sum * 100 / 500);
printf("\nYour total marks is %d",sum);
printf("\nYou got %d percentage",per);

getch();
}
