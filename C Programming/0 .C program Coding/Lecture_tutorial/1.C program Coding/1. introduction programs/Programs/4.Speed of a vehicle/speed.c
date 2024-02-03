#include<conio.h>
#include<stdio.h>
main()
{
    
 float speed,t,d;

    printf(" Enter the distance travelled in kilometers: ");
    scanf("%f",&d);

    printf(" Enter the time taken iin hours");
    scanf("%f",&t);
    speed=d/t;
    printf("\n The speed of the vehicle is  :- %fkm/hour",speed);

    getch();
}
