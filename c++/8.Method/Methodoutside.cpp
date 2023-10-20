# include <iostream>
using namespace std;
class student //create a class 
{
    public: //access secifire
    void method(); //method/function declaration
};
void student::method() //method/function defined outside the class
{
    cout<<"department"; //print
}
int main()
{
    student s1; //create a object of class
    s1.method(); //call the method/fun
}