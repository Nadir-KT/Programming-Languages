#include<iostream>
using namespace std;

class two;
class one
{
    int i;
    public:
    one(int m):i (m){}
    void display()
    {
        cout<<"\n one class member value is::"<<i;
    }
    friend void add(one,two);
};
class two
{
    int j;
    public:
    two(int m):j (m){}
    void display()
    {
        cout<<"\n two class member value is::"<<j;
    }
    friend void add(one,two);
};

void add (one x,two y)
{
    cout<<"\n addition of one and two classes members is::"<<x.i+y.j;
}
int main()
{
    class one a(10);
    a.display();
    class two b(20);
    b.display();
    add(a,b);
    cout<<"\n";
    return 0;
}