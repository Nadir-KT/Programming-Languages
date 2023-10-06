#include <iostream>
using namespace std;
int plusfunction(int x, int y) // create a function overloading
{
    return x+y; //sum of two number
}
double plusfunction(double x, double y) // create a function overloading
{
    return x+y; //sum of two number
}
int main() //intialize
{
    int mynum1=plusfunction(5, 5); //call the function
    double mynum2=plusfunction(1.5, .5); //call the function
    cout<<"int:"<<mynum1<<endl; //print int add of two number
    cout<<"double:"<<mynum2; //print double add of two number
    return 0;
}