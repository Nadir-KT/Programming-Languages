#include <iostream>
using namespace std;
void myfun(string country="norway")
{
    cout<<country<<endl;
}
int main()
{
    myfun("usa");
    myfun();
    myfun("india");
}