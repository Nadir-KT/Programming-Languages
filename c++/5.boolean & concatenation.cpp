#include <iostream>
using namespace std;
int main()
{
 bool embedded = true;
 bool design = false;
 cout<<embedded<<endl;  // Outputs 1 (true)
 cout<<design<<endl;  // Outputs 0 (false)
 string firstName = "arjun ";
 string lastName = " more ";
 string fullName = firstName + lastName;
 cout<<fullName<<endl;
 string firstName1 = "pooja ";
 string lastName1 = " thorat ";
 string fullName1 = firstName1.append(lastName1);
 cout << fullName1;
}



