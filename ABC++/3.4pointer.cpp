#include <iostream>

using namespace std;
int main()
{
    string fruit="Apple";
    string* ptr;
    ptr=&fruit;
    cout<<&fruit<<endl;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
}