# include <stdio.h>
# include <conio.h>
main()
{

int age, days,hours,min,sec;
printf("enter your age\n");
scanf("%d",&age);
days=age*365;
hours=days*24;
min=hours*60;
sec=hours*3600;
printf("My age: =%d \n", age);
printf("In days: =%d \n", days);
printf("In hours: =%d \n", hours);
printf("In minutes: =%d \n", min);
printf("In seconds: =%d \n", sec);
getch();
}
