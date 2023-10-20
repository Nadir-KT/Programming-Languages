#include <iostream>
using namespace std;
class student
{
    public: //public access specifire
     int x;
    private: //private access specifire
     int y; //private attribute
};
int main()
{
    student s1;
    s1.x=25;
    s1.y=55; //not allowed

}
