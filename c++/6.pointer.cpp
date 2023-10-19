#include <iostream>
using namespace std;
int main()
{
 int num=10; //variable declaration
 int* p; //pointer declaration
 p=&num; //store the address of number vaariable
 cout<<&num<<endl; // o/p print
 cout<<p<<endl;
 cout<<*p<<endl;
 string fruit="Apple"; //variable declaration
 string* ptr1; //pointer declaration
 ptr1=&fruit;
 cout<<&fruit<<endl;
 cout<<ptr1<<endl;
 cout<<*ptr1<<endl;
 int a=20, b=10,*p1=&a,*p2=&b;
 cout<<"before swap:*p1="<<*p1<<"*p2="<<*p2<<endl;;
 *p1=*p1+*p2;
 *p2=*p1-*p2;
 *p1=*p1-*p2;
 cout<<"after swap:*p1="<<*p1<<"*p2="<<*p2;
}
    
    