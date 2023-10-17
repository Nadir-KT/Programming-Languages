#include <iostream>
using namespace std;
class student //creating class
{
 public:
    int id; //initialization
    string name;
};
int main()
{
    student s1; //creating object of class
    s1.id=20; //access attributes and set value
    s1.name="pooja"; 
    cout<<s1.id<<endl; //print
    cout<<s1.name;
}