#include <iostream>
using namespace std;
class student
{
private:
    int rollno;
public:
    student()
    {
        rollno=10;
        cout << "I am constructor giving default values";
    }
    void printname()
    {
        cout << rollno;
    }

};
int main()
{
    student std1;
    std1.printname();
    return 0;
}
