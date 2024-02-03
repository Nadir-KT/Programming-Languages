#include<iostream>
using namespace std;
class vehicle //baseclass1
{
    public:
    vehicle()
    {
        cout<<"This is a vehicle\n";
    }
};
class fourwheeler : public vehicle
{
    public:
    fourwheeler()
    {
        cout<<"This is a 4 wheeler vehicle\n";
    }
};
class car : public fourwheeler
{
    public:
    car()
    {
        cout<<"car has 4 wheels\n";
    }
};
int main()
{
    car obj;
    return 0;
}