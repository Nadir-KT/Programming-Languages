#include <iostream>
using namespace std;
void print(int);
void print(int,int);
void print(int,int,int);
int main()
{
    print(10);
    print(12,23);
    print(34,56,677);
    return 0;
}
void print(int i)
{
    cout<<"Here is int "<<i<<endl;
}
void print(int i,int j)
{
    cout<<"two parm i "<<i<<endl;
    cout<<"two parm j "<<j<<endl;
}
void print(int i,int j,int k)
{
    cout<<"three parm i "<<i<<endl;
    cout<<"three parm j "<<j<<endl;
    cout<<"three parm k "<<k<<endl;
}
