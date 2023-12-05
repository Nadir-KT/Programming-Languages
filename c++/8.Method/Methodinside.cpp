#include <iostream>
using namespace std;
class student //create a class
{
    public: //access specifier
    void method() //method/function defined inside the class
    {
        cout<<"Hello world"; //print
    }
};
int main()
{
    student s1; //create an object of class
    s1.method(); //call the method/function
}