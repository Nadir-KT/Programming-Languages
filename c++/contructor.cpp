#include <iostream>
using namespace std;
class geek //define class
{
    public: //access identifier
    int id; //data member
    geek() //default constructor
    {
        cout<<"default constructor"<<endl;
        id=-1;
    }
    geek(int x) //parameterized constructor
    {
        cout<<"parameterized constructor"<<endl;
        id=x;
    }
};
    int main()
    {
        geek obj; //create a class of object
        cout<<"geek id is:"<<obj.id<<endl;
        geek obj1(21);
        cout<<"geek id is:"<<obj1.id<<endl;
    }
    
    
#include <iostream>
using namespace std;
class geek //define class
{
    public: //access identifier
    int id; //data member
    geek() //default constructor
    {
        cout<<"default constructor"<<endl;
        id=-1;
    }
    geek(int x) //parameterized constructor
    {
        cout<<"parameterized constructor"<<endl;
        id=x;
    }
};
    int main()
    {
        geek obj; //create a class of object
        cout<<"geek id is:"<<obj.id<<endl;
        geek obj1(21);
        cout<<"geek id is:"<<obj1.id<<endl;
    }
    
    
*******************************************************************************/
#include <iostream>
using namespace std;
class room //define class
{ 
 public:
 double length;
 double breadth;
 double height;
 double calculatearea()
 {
     return length*breadth;
 }
 double calculatevolume()
 {
     return length*breadth*height;
 }
};
int main()
{
    room room1; //create object of class
    room1.length=42.5; //assign values to data member
    room1.breadth=12.5;
    room1.height=24.5;
    cout<<"area of room="<<room1.calculatearea()<<endl;
    cout<<"volume of room="<<room1.calculatevolume()<<endl;
}
    




