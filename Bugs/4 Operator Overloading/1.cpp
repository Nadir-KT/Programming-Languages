#include <iostream>
using namespace std;
class complex{
    private:
    int real,imag;
    public:
    complex(int r=0,int i=0)
    {
        real = r;
        imag = i;
    }
    complex operator+(complex const &obj)
    {
        complex ret;
        ret.real = real + obj.real;
        ret.imag = imag + obj.imag;
        return ret;
    }
    void print()
    {
        cout <<real<<" + i"<<imag<<endl;
    }
};
int main()
{
    complex c1(10,5),c2(2,4),c4(23,34),c5(122,3434);
    complex c3 = c1+c2+c4+c5;
    c3.print();
    return 0;
}