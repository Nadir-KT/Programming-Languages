#include <iostream>
using namespace std;
int main()
{
    int *p = new int[10];
    p[0] = 10;
    p[1] = 20;
    cout << p[0];
    cout << p[1];
    delete p;
    return 0;
}
