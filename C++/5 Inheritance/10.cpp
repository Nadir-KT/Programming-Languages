#include <iostream> // std::cout
using namespace std;
class Base
{
    public:
    void baseFun()
    {
        cout<<"Base Function"<<endl;
    }
};
class Derived: public Base
{
    public:
    void derivedFun()
    {
        cout<<"Derived Fun"<<endl;
    }
};
int main()
{
    Derived dObj;
    //upcasting - implicit upcasting is allowed
    Base *bPtr = &dObj;
    bPtr -> baseFun();
    return 0;
}