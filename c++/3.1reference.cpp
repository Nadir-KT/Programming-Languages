#include <iostream>
using namespace std;
int main()
{
    string food="pizza"; //food variable
    string &meal=food; //reference to food
    cout<<food<<endl; //print
    cout<<meal<<endl;
}