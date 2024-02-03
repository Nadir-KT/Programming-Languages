#include<stdio.h>
struct student
{
    int no;
    char name[20];
    float fee;
};
void disp(struct student *stu1)
{
    printf("\n entered student details are as follows::\n");
    printf("\n Number::%d\n Name is::%s\n Fee::%f",stu1->no,stu1->name,stu1->fee);
    printf("\n");
}
void main()
{
    struct student stu;
    printf("\n enter student name, no, fee::");
    scanf("%s%d%f",stu.name,&stu.no,&stu.fee);
    disp(&stu);
}
