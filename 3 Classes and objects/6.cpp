#include <iostream>>
using namespace std;

class sample1
{
    private:
    int i;
    const int m;
    public:
    sample1(int, int);
    void print()
    {
        cout<<"\n normal class member value is ::"<<m;
    }
    ~sample1()
    {
        cout<<"\n we are in destructor..\n";
    }
};

sample1::sample1(int a ,int m1):m(m1) //should use initialiser for constants
{
    i=a;
}

int main()
{
    class sample1 c1(10,20);
    c1.print();
    return 0;
}