#include<stdio.h>
#include<stdlib.h>
int main()
{float distance,time,speed;
    printf("Enter the distance traveled in kilometers : ");
    scanf("%f",&distance);
    printf("Enter the time taken in hours : ");
    scanf("%f",&time);
    speed=distance/time;
    printf("The speed of the vehicle is  : %f km/hour\n",speed);
system("pause");}
