#include <iostream>
using namespace std;
void myfun(int mynum[2])
{
    for(int i=0; i<2; i++)
    {
        cout<<mynum[i]<<endl;
    }
}
int main()
{
    int mynum[2]={10,20};
    myfun(mynum);
}