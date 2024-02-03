# include<stdio.h>
# include<stdlib.h>
int main(){int age,days,hours,min,sec;
printf("Enter your age\n");
scanf("%d",&age);
days=age*365;
hours=days*24;
min=hours*60;
sec=min*60;
printf("Age : %d\n",age);
printf("In days : %d\n",days);
printf("In hours : %d\n",hours);
printf("In minutes : %d\n",min);
printf("In seconds : %d\n",sec);
system("pause");}
