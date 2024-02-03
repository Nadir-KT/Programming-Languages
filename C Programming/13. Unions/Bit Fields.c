#include <stdio.h>
int main()
{
struct person_details
{
    unsigned gen:1;
    unsigned age:7;
    unsigned child:2;
    unsigned m_status:1;
}pd;

    int i;
    printf("\n enter ur gen(0-Female 1-Male)");
    scanf("%d",&i);
    pd.gen=i;
    printf("\n enter ur age");
    scanf("%d",&i);
    pd.age=i;
    printf("\n enter how many childs ");
    scanf("%d",&i);
    pd.child=i;
    printf("\n enter ur m_status (0-married 1-Unmarried)");
    scanf("%d",&i);
    pd.m_status=i;
    printf("\n person details are as follows");
    printf("\n Gender ::");

    if(pd.gen)
        printf(" MALE");
    else
        printf(" FEMALE");

    printf("\n Age :: %d",pd.age);
    printf("\n Childrens :: %d",pd.child);
    printf("\n Marriage status ::");

    if(pd.m_status)
        printf(" MARRIED");
    else
        printf(" UNMARRIED");
    printf("\n");

    return 0;
}
