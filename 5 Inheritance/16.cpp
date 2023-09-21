#include<iostream>
using namespace std;
template <class T>
void print(T val)
{
    cout<<"\n value is::"<<val;
}
int main()
{
    print<int>(10);
    print<char>('c');
    print<float>(10.302);
    return 0;
}