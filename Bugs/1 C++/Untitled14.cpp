#include <iostream>
using namespace std;
void print(int);
void print(char);
int main()
{
    print(10);
    print('A');
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
