#include <iostream>
using namespace std;
void myfunction(int mark[5]) //declare a function
{   
    cout<<"Display mark:"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"student "<<i + 1<<":"<<" Aarti "<<" "<<mark[i]<<endl;
    }
}
int main()
{ 
    int mark[5]={88, 85, 45, 75, 90}; //declare & initialize array
    myfunction(mark);
    return 0;
}