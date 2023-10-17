#include <iostream>
using namespace std;
int main()
{
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10;j++)
        {
            if(i==5)
            {
                continue;
            }
            if(j==4)
            {
            break;
            }
            cout<<i<<" "<<j<<endl;
         }
    }
}