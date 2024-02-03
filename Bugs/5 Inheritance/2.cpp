#include <iostream>
using namespace std;
class vehicle
{
    public:vehicle()
    {
        cout<<"This is a vehicle";
    }
};
class car:public vehicle{};
int main()
{
    vehicle obj;
    return 0;
}