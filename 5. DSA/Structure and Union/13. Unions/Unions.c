#include<stdio.h>
void main()
{
    union stu
    {
        int a;
        float b;
        double c;
    };
    union stu s;
    s.a = 10;
    printf("%d\n",s.a);
    s.b = 20.5;
    printf("%d\n",s.a);
    printf("%f\n",s.b);
}
