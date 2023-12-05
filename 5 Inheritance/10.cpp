#include <iostream> 
using namespace std;
class base
{
    public:
    void baseFun()
    {
        cout<<"base Function"<<endl;
    }
};
class derived: public base
{
    public:
    void derivedFun()
    {
        cout<<"derived Fun"<<endl;
    }
};
int main()
{
    derived dObj;
    //upcasting - implicit upcasting is allowed
    base *bPtr = &dObj;
    bPtr -> baseFun();
    return 0;
}