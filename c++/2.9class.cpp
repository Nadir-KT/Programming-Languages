#include <iostream>
using namespace std;
struct car
{
    string brand;
    int year;
};
int main()
{
    car car1;
    car1.brand="BWM";
    car1.year=1923;
    car car2;
    car2.brand="hexa";
    car2.year=2011;
    cout<<car1.brand<<" "<<car1.year<<endl;
    cout<<car2.brand<<" "<<car2.year<<endl;
}