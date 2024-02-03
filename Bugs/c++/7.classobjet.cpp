#include <iostream>
using namespace std;
class student //creating class
{
 public: //Access specifire
    int id; //initialization Attribute (int variable)
    string name; 
    string clgname;
};
int main()
{
    student s1; //creating object of class
    s1.id=20; //access attributes and set value
    s1.name="pooja";
    s1.clgname="SSGMCE";
    cout<<"Enter student id :"<<s1.id<<endl; //print attributes
    cout<<"Enter student name: "<<s1.name<<endl;
    cout<<"Enter college name: "<<s1.clgname<<endl;
}