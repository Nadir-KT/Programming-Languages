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
    car c1("BWM", 1992); //create car obj & call the constructor with different value
    cout<<"Brand name: "<<c1.brand<<endl; //print value
    cout<<"Year: "<<c1.year<<"\n"; //printvalue
}


