#include<stdio.h>
void main()
{
int n,i;
struct student { int no; char name[20]; float fee; };
struct student stu[100];
printf("\n enter how many records you are going to enter::");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\n enter %d record::",i+1);
printf("\n enter student name, no, fee::");
scanf("%s%d%f",stu[i].name,&stu[i].no,&stu[i].fee);
}
printf("\n entered student details are as follows::\n");
for(i=0;i<n;i++){
printf("\n %d record is",i+1);
printf("\n Number::%d\n Name is::%s\n Fee::%f",stu[i].no,stu[i].name,stu[i].fee);
printf("\n address are as follows::");
printf("\n number::%u\n name::%u\n fee::%u",&stu[i].no,&stu[i].name,&stu[i].fee);
}
printf("\n size of atructure is::%d",sizeof(stu[0]));
printf("\n");
}
