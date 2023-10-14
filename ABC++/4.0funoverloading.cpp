#include <iostream>
using namespace std;
int pfun(int x, int y)
{
    return x+y;
}
double pfun(double x, double y)
{
    return x+y;
}
string pfun(string s1, string s2)
{
    return s1+s2;
}
int main()
{
    int mynum1=pfun(5,2);
    double mynum2=pfun(1.5,1.5);
    string student=pfun("pooja "," jyoti ");
    cout<<mynum1<<endl;
    cout<<mynum2<<endl;
    cout<<student;
}