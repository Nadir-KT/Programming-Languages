#include <iostream>
using namespace std;
struct student //structure declaration
{
    int id; //member int variable 
    string name;
};
int main()
{
student j1;
j1.id=20;
j1.name="pooja";
cout<<j1.id<<" "<<j1.name<<endl; //rint structue member
}