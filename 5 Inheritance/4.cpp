#include<iostream>
using namespace std;
class car //baseclass1
{
    public:
    car()
    {
        cout<<"This is a car\n";
    }
};
class fourwheeler : public car
{
    public:
    fourwheeler()
    {
        cout<<"This is a 4 wheeler car\n";
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