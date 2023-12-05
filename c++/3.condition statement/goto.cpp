#include <iostream>
using namespace std;
int main()
{
    int age; //initialize
    cout<<"enter your age:"; //print
    cin>>age;
    if(age<18)
    {
        cout<<"you are not eligible to vote"<<endl;
    }
    else
    {
        cout<<"you are eligible to vote";
    }
}
