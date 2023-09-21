#include <iostream>
using namespace std;
class student
{
public:
    int rollno;
    void printname()
    {
        cout << "student";
    }
};
int main()
{
    student std1;
    std1.rollno = 10;
    std1.printname();
    cout << std1.rollno <<endl;
    return 0;
}
