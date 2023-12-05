#include <iostream>
using namespace std;
class student //define class
{
    public: //Acccess specifier
    void mymethod() //method/fun defined inside the class
    {
        cout<<"ssgmce"; //print
    }
};
int main() //
{
    student eng; //create a object of class
    eng.mymethod(); //call the method
    
}
