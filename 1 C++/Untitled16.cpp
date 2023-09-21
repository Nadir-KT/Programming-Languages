#include <iostream>
using namespace std;
void print(int);
void print(double);
void print(char);
int main()
{
    print(10);
    print('A');
    print(12.45);
    return 0;
}
void print(int i)
{
    cout<<"Here is int "<<i<<endl;
}
void print(char i)
{
    cout<<"Here is char "<<i<<endl;
}
void print(double i)
{
    cout<<"Here is double "<<i<<endl;
}
