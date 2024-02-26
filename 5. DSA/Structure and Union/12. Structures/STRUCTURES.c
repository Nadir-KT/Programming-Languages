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
    printf("\n enter student name, no, fee::");
    scanf("%s %d %f",stu.name, &stu.no, &stu.fee);
    printf("\n entered student details are as follows::\n");
    printf("\n Number::%d\n Name is::%s\n Fee::%f ", stu.no, stu.name, stu.fee);
    printf("\n address are as follows::");
    printf("\n number::%u \n name::%u\n fee::%u ",&stu.no,&stu.name,&stu.fee);
    printf("\n size of atructure is::%d ",sizeof(stu));
    printf("\n");
}
