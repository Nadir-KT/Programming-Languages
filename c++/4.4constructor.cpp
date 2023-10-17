#include <iostream>
using namespace std;
class car //create a class
{
    public: //access specifire
     string brand; //attribute
     int year;
     car(string x, int y) //constructor with parameter
     {
         brand = x;
         year = y;
     }
};
int main()
{
    car c1("bmw", 1992); //create car obj & call the constructor
    cout<<c1.brand<<" "<<c1.year<<"\n"; //print
}


