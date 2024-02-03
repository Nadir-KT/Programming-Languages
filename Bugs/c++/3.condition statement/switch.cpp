#include <iostream>  
using namespace std;  
int main ()
{  
    int num; //initialize
    cout<<"Enter a number to check grade:"; //print    
    cin>>num; 
    switch(num)
    {
        case 10:
        cout<<"it is 10";
        break;
        case 20:
        cout<<"it is 20";
        break;
        default:
        cout<<" is not 10 or 20";
        break;
    }
      
}