#include<iostream>
using namespace std;

class sample1
{
    private:
    float x;
    public:
    float y;
    sample1(float a,float b);
    sample1(sample1 &s)
    {
        x=s.x;
        y=s.y;
    }
    void print();
    ~sample1();
};

sample1::sample1(float a,float b)
{
    cout<<"\n we are in constructor";
    x=a;
    y=b;
}

void sample1::print()
{
    cout<<"\n we are in class member function";
    cout<<"\n x value is::"<<x;
    cout<<"\n y value is::"<<y;
}

sample1::~sample1()
{
    cout<<"\n we are in destructor";
}

int main()
{
    class sample1 s1(10.23,45.54);
    class sample1 s2(s1); //calls copy constructor
    class sample1 s3=s1; //calls assignment operator
    cout<<"\n we are in main";
    s1.print();
    s2.print();
    s3.print();
    cout<<"\n";
    return 0;
}