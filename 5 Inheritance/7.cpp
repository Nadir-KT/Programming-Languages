#include<iostream>
using namespace std;
template <class T>
class array {
    T arr[20];
    public:
    array(){
        for(int i=0;i<5;i++)
        arr[i]=0;
    }
    void read(){
        cout<<"\n enter elements...\n";
        for(int i=0;i<5;i++)
        cin>>arr[i];
    }
    void display(){
        cout<<"\n entered elements are as follows...\n";
        for(int i=0;i<5;i++)
        cout<<arr[i]<<"\t";
    }
};
int main()
{
    class array<int> a;
    cout<<"\n now we are creating integer array";
    a.read();
    a.display();
    class array<char> b;
    cout<<"\n now we are creating char array";
    b.read();
    b.display();
    class array<double> c;
    cout<<"\n now we are creating float array";
    c.read();
    c.display();
    cout<<"\n";
    return 0;
}
