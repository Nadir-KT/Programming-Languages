#include<iostream>
using namespace std;
class A 
{
    int a_int;
    char* a_carp;
    public:
    void display()
    {
        cout<<"\n we are in A class::";
        cout<<a_int<<"\t"<<a_carp;
    }
    void getdata(int x, char *y)
    {
        a_int=x;
        a_carp=y;
    }
    operator int() 
    { 
        return a_int; 
    }
    operator char*() 
    { 
        return a_carp; 
    }
};
class B : public A 
{
    float b_float;
    char* b_carp;
    public:
    void print()
    {
        cout<<"\n we are in B class::";
        cout<<b_float<<"\t"<<b_carp;
    }
    void setdata(float x, char *y)
    {
        b_float=x;
        b_carp=y;
        }
        operator float() 
        { 
            return b_float; 
        }
        operator char*() 
        {
            return b_carp; 
        }
};
int main () 
{
    A a_obj;
    cout<<"\n a object members values are as follows::";
    a_obj.getdata(23,"ism");
    a_obj.display();

    B b_obj;
    cout<<"\n b object member values are as follows::";
    b_obj.setdata(10.23,"tech");
    b_obj.print();
    
    // long a = b_obj; //error becase long is not a member of B class
    cout<<"\n\n we are going to type cast to class object to int::";
    int i=a_obj;
    cout<<"\n after typecast by using \"A\" object value is::"<<i;
    
    cout<<"\n\n we are going to type cast class object to float";
    float f=b_obj;
    cout<<"\n after trypecast by using \"B\" object value is::"<<f;
    
    cout<<"\n\n now we are going to typecast class object to char pointer";
    char *cptr=a_obj;
    cout<<"\n after typecast by using \"A\" object value is:"<<cptr;
    
    cout<<"\n";
}