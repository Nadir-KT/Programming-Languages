#include <iostream>
using namespace std;
class Account //base class
{
    public:
    float salary=6000;
};
class programmer:public Account //derived class
{
    public:
    float bonus=5000;
};
int main(void)
{
    programmer p1;
    cout<<"salary: "<<p1.salary<<endl;
    cout<<"Bonus: "<<p1.bonus<<endl;
}