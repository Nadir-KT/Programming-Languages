#include<stdio.h>
//#pragma pack(1)

int main()
{
    struct sample
    {
        int a;
        char b;
        int c;
    }__attribute__((packed));
    struct sample s;

    printf("\n%d\n",sizeof(s));
return 0;
}
