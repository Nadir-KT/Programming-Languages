#include<iostream>
using namespace std;
class Base
{
    int x;
    public:
    virtual void fun() = 0;
    int getx() 
    { 
        return x;
    }
};
// This class inherits from Base and impliments fun()
class Derived: public Base
{
    int x;
    public:
    void fun() 
    { 
        cout << "fun() called"; 
        
    }
};
int main(void)
{
    Derived d;
    d.fun();
    return 0;
}