#include <iostream>
using namespace std;
class Vehicle //baseclass
{
    public:
    Vehicle()
    {
        cout << "This is a vehicle" << endl;
    }
};
class Fare
{
    public:
    Fare()
    {
        cout << "Fare of Vehicle\n";
    }
};
class Car : public Vehicle //derived class1
{

};
class Bus : public Vehicle //derived class2
{

};
int main()
{
    Bus obj2;
    
    return 0;
}