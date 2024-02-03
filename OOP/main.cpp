// C++ program to demonstrate
// Class

#include <bits/stdc++.h>
using namespace std;

class Learns {
    // Access specifier
public:
    // Data Members
    string learnname;

    // Member Functions()
    void printname()
    {
        cout << "Learnname is: " << learnname;
    }
};

int main()
{

    // Declare an object of class geeks
    Learns obj1;

    // accessing data member
    obj1.learnname = "Learn eTutorials";

    // accessing member function
    obj1.printname();

    return 0;
}