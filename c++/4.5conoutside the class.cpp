#include <iostream>
using namespace std;
class car //create a class
{
    public: //access specifire
    string brand; //attribute
    int year;
    car(string x, int y); //constructor declaration
};
car::car(string x, int y) //con define outside the class
{
    brand = x;
    year =y ;
}
int main()
{
    car c1("BWM", 2020); //create car object & call the con with different value
    cout<<c1.brand<<" "<<c1.year; //print
}
