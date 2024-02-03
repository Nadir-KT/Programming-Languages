#include <iostream>
using namespace std;
int main()
{
    int *p1 = new int[10];
    p1[0] = 10;
    p1[1] = 20;
    cout << p1[0]<<endl;
    cout << p1[1];
    return 0;
}