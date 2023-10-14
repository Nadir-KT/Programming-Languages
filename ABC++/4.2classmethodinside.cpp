#include <iostream>
using namespace std;
class student //create class
{
    public: //access specfire
    void method() //method/fun define inside the class
    {
        cout<<"hello world"; //print
    }
};
int main()
{
    student s1; //create object of class
    s1.method(); //call the method
}