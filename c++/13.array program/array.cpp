#include <iostream>
using namespace std;
int main()
{
    int mat[3][3]=
    {
        {0,2,9},
        {2,3,0},
        {9,7,0}
    };
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            cout<<mat[i][j]<<" ";
        }
        
            cout<<endl;
        }
}