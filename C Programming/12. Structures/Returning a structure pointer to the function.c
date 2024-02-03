#include<stdio.h>
struct student
{
    int no;
    char name[20];
    float fee;
}stu;
void disp(struct student *);
struct student *read()
{
    printf("\n enter student name, no, fee::");
    scanf("%s%d%f",stu.name,&stu.no,&stu.fee);
    return &stu;
}
void main()
{
    struct student *stu;
    stu=read();
    disp(stu);
}
void disp(struct student *stu1)
{
    printf("\n entered student details are as follows::\n");
    printf("\n Number::%d\n Name is::%s\n Fee::%f",stu1->no,stu1->name,stu1->fee);
    printf("\n");
}
