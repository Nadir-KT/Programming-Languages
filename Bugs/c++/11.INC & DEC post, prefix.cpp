#include <iostream>
using namespace std;
int main()
{
    float pi;
    float r,cir;
    cout<<"enter the radius of circle:";
    cin>>r;
    cir=r*r*3.14;
    cout<<"area of circle is:"<<cir<<endl;
    int a=4;
    int c;
    c=a++;
    cout<<"result of 1 value c is:"<<c<<endl;
    cout<<"result of 2 value a is:"<<a<<endl;
    int a1=8;
    int c1;
    c1=a1--;
    cout<<"result of 1 value c1 is:"<<c1<<endl;
    cout<<"result of 2 value a1 is:"<<a1<<endl;
    int a2=12;
    int c2;
    c2=++a2;
    cout<<"result of 1 value c2 is:"<<c2<<endl;
    cout<<"result of 2 value a2 is:"<<a2<<endl;
    int a3=20;
    int c3;
    c3=--a3;
    cout<<"result of 1 value c3 is:"<<c3<<endl;
    cout<<"result of 2 value a3 is:"<<a3<<endl;
    return 0;
}