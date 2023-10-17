#include <iostream>
using namespace std;
class student //create class
{
    public: //access specifire
    void method(); //method/fun declaration
};
student std::method() //method/fun definition outside the class
{
    cout<<"hello world"; //print
}
int main()
{
    student s1; //create object of class
    s1.method(); //call the method
}