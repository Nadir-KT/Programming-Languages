#include<stdio.h>
void main()
{
    struct student
    {
        int no;
        char name[20];
        float fee;
    };
    struct student stu;
    struct student *ptr;
    ptr=&stu;
    printf("\n enter student name, no, fee::");
    scanf("%s%d%f",ptr->name,&ptr->no,&ptr->fee);
    printf("\n entered student details are as follows::\n");
    printf("\n Number::%d\n Name is::%s\n Fee::%f",ptr->no,ptr->name,ptr->fee);
    printf("\n");
}
