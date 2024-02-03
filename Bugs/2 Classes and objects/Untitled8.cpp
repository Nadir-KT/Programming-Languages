#include <iostream>
using namespace std;
class student
{
private:
    int rollno;
public:
    student(int a)
    {
        rollno=a;
        cout << "I am constructor giving default values";
    }
    void printname()
    {
        cout << rollno;
    }

};
int main()
{
    student std1(20);
    std1.printname();
    return 0;
}

