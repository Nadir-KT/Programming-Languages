#include <iostream>
using namespace std;
int main()
{
    int r=2, c=3, sum[2][3], i, j;
    int a[2][3] = { {1,5,9}, {3,2,8}};
    int b[2][3] = { {6,3,8}, {1,5,2}};
    cout<<"The first matrix is:"<<endl;
    for(int i=0; i<r; ++i)
    {
        for(int i1=0;i1<c;++i1)
        cout<<a[i][i1]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<"The second matrix is: "<<endl;
    for(int i=0; i<r; ++i)
    {
        for(int i1=0; i1<c; ++i1)
        cout<<b[i][i1]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<r; ++i)
    for(int i1=0;i1<c;++i1)
    sum[i][i1]=a[i][i1]+b[i][i1];
    cout<<"sum of the two matrices is:"<<endl;
    for(int i=0; i<r; ++i)
    {
        for (int i1=0; i1<c;++i1)
        cout<<sum[i][i1]<<" ";
        cout<<endl;
    }
}
