#include<stdio.h>
void main()
{
    struct samp
    {
        int data;
        struct samp *node;
    }s1,s2;

    s1.data=10;
    s1.node=&s2;
    s2.data=20;
    s2.node=NULL;

    printf("\n sizeof s1 is::%d\n sizeof s2 is::%d",sizeof(s1),sizeof(s2));
    printf("\n address of s1 is::%p",&s1);
    printf("\n address of s1 data is::%p",&s1.data);
    printf("\n asddress of s1 node is::%p",&s1.node);
    printf("\n value at s1 data is::%d",s1.data);
    printf("\n value at s1 node is::%p",s1.node);
    printf("\n address of s2 is::%p",&s2);
    printf("\n address of s2 data is::%p",&s2.data);
    printf("\n asddress of s2 node is::%p",&s2.node);
    printf("\n value at s2 data is::%d",s2.data);
    printf("\n value at s2 node is::%p",s2.node);
}
