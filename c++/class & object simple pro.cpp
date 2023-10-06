*******************************************************************************/
#include <iostream>
using namespace std;
class student //define class
{
    public: //Access specifier
    int id; //attribute (int variable)
    string name;
};
int main()
{
    student s1; //create a object of class 
    s1.id=302; //Access attributed & set value
    s1.name="pooja"; 
    cout<<s1.id<<endl; //print attribute value
    cout<<s1.name<<endl;
    return 0;
}
