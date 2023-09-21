
#include <iostream>
using namespace std;
int &incr(int );
int main()
{
    int n=8;
    cout << incr(n);
}
int &incr(int b)
{
    static int a=10;
    cout<<a;
    a++;
    return a;
}
