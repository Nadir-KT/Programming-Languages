#include<iostream>
using namespace std;
class sample1
{
    int i;
    static int f;
    public:
    sample1()
    {
        cout<<"\n\n we are in no argumented constructor..";
        i=0;
        f++;
        print();
    }

    sample1(int a)
    {
        cout<<"\n\n  we are in one argumented constructor..";
        i=a;
        f++;
        print();
    }

    void print()
    {
        cout<<"\n"<<f<<" number of objects(s) are created..";
        cout<<"\n normal class member value is::"<<i;
    }
    ~sample1()
    {
        cout<<"\n we are in destructor..\n";
    }
};

int sample1::f=0;

int main()
{
    class sample1 c1,c2(10),c3,c4(20);
    return 0;
}