#include<iostream>
using namespace std;

int i=0;

class subscript
{
    int array[10];

public:
    subscript(int k)
    {
        for(i=0;i<10;array[i]=k,i++);
    }
    
    int &operator[](int k)
    {
        if(k >= 10)
        {
            cout<<"\n wrong subscript...\n";
            exit(1);
        }
        else
        return array[k];
    }
};

int main()
{
    class subscript ss(0);
    cout<<"\n now we are going to place 13 element in 2nd index";
    ss[2]=13;
    cout<<"\n now we are going to place 22 element in 10 index";
    ss[10]=22; // error because size is exceeding
}