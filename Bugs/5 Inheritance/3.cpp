#include<iostream>
using namespace std;
class Vehicle //baseclass1
{
    public:
    Vehicle()
    {
        cout<<"This is a vehicle"<<endl;
    }
};
class Fourwheeler //baseclass2
{
    public:
    Fourwheeler()
    {
        cout<<"This is a 4 wheeler vehicle"<<endl;
    }
};
class car:public Vehicle,public Fourwheeler
{};
int main()
{
    car obj;
    return 0;
}