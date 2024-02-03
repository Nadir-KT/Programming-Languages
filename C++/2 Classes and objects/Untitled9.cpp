#include <iostream>
using namespace std;
class student
{
private :
    int x;
    int y;
public :
    student(int a,int b)
    {
        x=a;
        y=b;
        cout << "I am constructor giving default values";
        cout << "\n";
    }
    void pass(int a,int b)
    {
        x=a;
        y=b;
    }
    void printname()
    {
        cout << x;
        cout << "\n";
        cout << y;
        cout << "\n";
    }
};
int main()
{
    student std1(10,20);
    std1.printname();
    std1.pass(25,65);
    std1.printname();
    return 0;
}
