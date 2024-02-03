#include<iostream>
using namespace std;

class Number
{
    int n;

public:
Number(int a=0)
{
    n=a;
}
void print();
Number operator++();
};

void Number::print()
{
    cout<<"Number="<<n;
}

Number Number::operator++()
{
    n++;
    return *this;
}
int main()
{
    Number ob1(10);
    Number ob2;
    ob2 = ++ob1; //obj1.operator++();
    ob1.print();
    ob2.print();
}