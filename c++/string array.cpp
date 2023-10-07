/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
void myfunction(int mark[6],std::string stlstrings[]) //declare a function
{   
    cout<<"Display mark:"<<endl;
    for(int i=0; i<6; i++)
    {
        cout<<"student "<<i + 1<<":"<<stlstrings[i]<<" "<<mark[i]<<endl;
    }
}
int main()
{ 
    int mark[6]={88, 85, 45, 75, 90, 100}; //declare & initialize array
    std::string stlstrings[]{"uniform", "victor", "whiskey", "x-ray", "yankee", "zulu"}; 
    myfunction(mark,stlstrings);
    return 0;
}