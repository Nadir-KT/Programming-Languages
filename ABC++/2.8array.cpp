#include <iostream>
using namespace std;
int main()
{
    int test[3][3]=
    {
        {5,10,0},{0,15,20},{30,0,10}
    };
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }
}
    