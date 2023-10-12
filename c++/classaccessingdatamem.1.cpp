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

#include <iostream>
using namespace std;
class geek //define class
{
public: //access specifire
string geekname; //data member
int id;
void printname(); //member function
void printid()
{
    cout<<"printid id:"<<id; //printid inside the class
}
};
void geek::printname()
{
    cout<<"geekname is: "<<geekname; //printname using scope resolution operator
}  
int main()
{
    geek obj; //create object of class
    obj.geekname="shree"; //accessing data member
    obj.id=4;
    obj.printname();//accessing member function
    cout<<endl;
    obj.printid();
}