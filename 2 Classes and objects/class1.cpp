#include <iostream>
using namespace std;
class greek //define class
{
 public: //access specifier
 string greekname; //data member
 void printname() //member function
 {
     cout<<"greekname is:"<<greekname;
 }
};
int main()
{
    greek obj; //crete object of class greek
    obj.greekname="rushi"; //accessing data member
    obj.printname(); //accessing member function
}