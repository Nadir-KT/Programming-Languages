#include <iostream>
using namespace std;
int main()
{
    int x=5, y=8, u=5, v=5, z=8, w=5, p=5, r=5, s=5, t=5;
    cout<<x<<endl;
    ++x;
    cout<<x<<endl; 
    --y;
    cout<<y<<endl;
    u +=3;
    cout<<u<<endl;
    v -=3;
    cout<<v<<endl;
    w *=3;
    cout<<w<<endl;
    y /=2;
    cout<<y<<endl;
    z %=3;
    cout<<z<<endl;
    w &=3;
    cout<<w<<endl;
    p |=3;
    cout<<p<<endl;
    r ^=3;
    cout<<r<<endl;
    s >>=3;
    cout<<s<<endl;
    t <<=3;
    cout<<t<<endl;
    cout<<(p>3 && p<10)<<endl;
    cout<<(p>3 || p<4)<<endl;
    cout<<(!(p>3 && p<10))<<endl;
    cout<<(x>y)<<endl;
    cout<<(x<y)<<endl;
    cout<<(x==y)<<endl;
    cout<<(x!=y)<<endl;
    cout<<(x<=y)<<endl;
    cout<<(x>=y)<<endl;
}

