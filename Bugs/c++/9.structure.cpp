#include <iostream>
using namespace std;
struct student //structure declaration
{
    int id; //member (int variable)
    string name;
};
int main()
{
    student s1; //create a object of class(create a student structure and store it in s1)
    s1.id=20;
    s1.name="pooja";
    cout<<"Enter student id : "<<s1.id<<endl; //print the structure member
    cout<<"Enter student name: "<<s1.name<<endl;
}