#include <iostream>
using namespace std;
int main()
{
    int i=1;
    while(i<=3)
    {
        int j=1;
        do
        {
         for(int k=1; k<=3; k++)
          {
            cout<<i<<" "<<j<<" "<<k<<endl;
            j++;
            i++;
          }
        }
          while(j<=3);
    }
 }
