#include<iostream>
using namespace std;
class parent
{
    public:int id_p;
};
class child:public parent
{
    public:int id_c;
};
int main()
{
    child obj;
    obj.id_c=71;
    obj.id_p=91;
    cout<<"child id is "<<obj.id_c;
    cout<<"\nparent id is "<<obj.id_p;
    return 0;
}