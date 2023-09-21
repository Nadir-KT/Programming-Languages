#include <iostream>
using namespace std;
int sum(int a,int b=0,int c=0)
{
    return a+b+c;
}
int main()
{
    int x,y,z;
    x=13;
    y=23;
    cout << sum(x,y);
//    cout << sum(x);
    return 0;
}
