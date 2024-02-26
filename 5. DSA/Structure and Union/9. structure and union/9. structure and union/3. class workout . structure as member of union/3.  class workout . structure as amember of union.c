#include<stdio.h>
#include<conio.h>

main()
{
  struct student
    {
     char name[30];
         int rollno;
     float percentage;
    };

    union details
     {
         struct student st;
     };
     union details set;

printf("Enter details:");
printf("\nEnter name : ");
scanf("%s", set.st.name);

printf("\nEnter rollno: ");
scanf("%d", &set.st.rollno);

printf("\nEnter percentage: ");
scanf("%f",&set.st.percentage);

printf("\nThe student details are:");
printf("Name : %s", set.st.name);
printf("\nRollno : %d", set.st.rollno);
printf("\nPercentage : %f", set.st.percentage);

getch();
}
