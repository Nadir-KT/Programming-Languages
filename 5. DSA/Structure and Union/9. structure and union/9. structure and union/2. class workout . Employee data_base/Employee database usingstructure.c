#include<stdio.h>
#include<conio.h>


void main()
{
int i,j,n;




struct emp
{
char emp_name[40];
int emp_no;
char emp_department[10];
int emp_salary;
};struct emp emp_details[1];




printf("No of Emploees to be Entered : ");
scanf("%d",&n);
i=0;
while(i<n)
{
printf("\n Enter Employee Name :");
scanf("%s",emp_details[i].emp_name);
printf("\n Enter Employee No :");
scanf("%d",&emp_details[i].emp_no);
printf("\n Enter Employee Department :");
scanf("%s",emp_details[i].emp_department);
printf("\n Enter Employee Salary in Rs :");
scanf("%d",&emp_details[i].emp_salary);
i++;
}

printf("\n Entered Details are..");
j=0;
while(j<n)
{
printf("\n Employee Name : %s",emp_details[j].emp_name);
printf("\n Employee No : %d",emp_details[j].emp_no);
printf("\n Employee Department : %s",emp_details[j].emp_department);
printf("\n Employee Salary in Rs : %d",emp_details[j].emp_salary);
j++;
}
getch();
}
