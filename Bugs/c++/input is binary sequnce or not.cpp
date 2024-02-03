#include <iostream>  
using namespace std;  
int main()  
{ 
int a[10], n, i; 

cout<<"Enter the binary number:";
cin>>n;    
{    
a[i]=n%2;    
n= n/2;  
}    
for(i=i-1 ;i>=0 ;i--)    
{    
cout<<a[i];    
}  
if(a[i]=n%2)
{    
                cout<<"It is binary number";    
            }   
            else  
            {    
                cout<<"It is not binary number";    
            }  
}  
