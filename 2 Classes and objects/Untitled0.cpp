#include <iostream>
using namespace std;
int main()
{
    int x,y;
    x=13;
    y=23;
    swap(x,y);
    cout<<x<<" "<<y;
    return 0;
}
void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
