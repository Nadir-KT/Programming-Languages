#include<iostream>
using namespace std;
class sample1
{
private:
    float x;
public:
    float y;
    void setdata(float a,float b)
    {
        x=a;
        y=b;
    }
    float getx()
    {
        return x;
    }
    float gety()
    {
        return y;
    }
    void print()
    {
        cout<<"\n we are in class member function";
        cout<<"\n x value is::"<<x;
        cout<<"\n y value is::"<<y;
    }
};
int main()
{
    class sample1 s1;
    s1.print();
    s1.setdata(10.32,45.56);
    cout<<"\n we are in main";
    cout<<"\n x value is::"<<s1.getx();
    cout<<"\n y value is::"<<s1.gety();
    s1.print();
    cout<<"\n";
    return 0;
}
