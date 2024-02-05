#include <iostream>
#include <string>   // Include the string library
using namespace std;
int main(void)
{
    // Create variables
    int myNum = -5;				// Integer (whole number)
    float myFloatNum = 5.99;	// Floating point number
    double myDoubleNum = 9.98;	// Floating point number
    char myLetter = 'D';		// Character
    bool myBoolean = true;		// Boolean
    string myText = "Hello";	// String
    float f1 = 35e3;
    double d1 = 12E4;
    bool isCodingFun = true;
    bool isFishTasty = false;
    char a = 65, b = 66, c = 67;
    // Print variables
    cout << f1 << endl;
    cout << d1 << endl;
    cout << isCodingFun << endl;  // Outputs 1 (true)
    cout << isFishTasty << endl;  // Outputs 0 (false)
    cout << myLetter << endl;
    cout << a;
    cout << b;
    cout << c << endl;
    cout << myText << endl;
	// C++ Type Conversion
	// new-type(expression);    // C++ function cast notation
    // (new-type)expression;    // C-language cast notation
	double weight1 = 154.49;
	cout << int(weight1) << endl;
	int weight2 = weight1; // Implicit conversion by the compiler
	cout << weight2 << endl;
	int weight3 = (int) weight1;  // Explicit type conversion
	cout << (int)weight1 << endl; // Explicit type conversion
	cout << weight3 << endl;
	typedef unsigned long ulong; //typedef type newname; create a new name for an existing type
	ulong distance=10;
	cout << distance;
	typedef int* IntPtr ; //typedef can be used to give an alias name to pointers also.
	IntPtr g, h, i; //same as//int*  g, h, i; 
	enum color { red, green, blue } z,x; //enum enum-name { list of names } var-list;
	z = blue;
	enum color2 { red2, green2 = 5, blue2 };
	cout <<"\ncolor="<<z;
	cout <<"\ncolor2="<<green2 << endl;
	wchar_t chr = L'R'; //data type that is larger than an 8-bit character
	wchar_t test = L'?'; //The literal must be stored in wchar t if the character is followed by an L. 
	cout << chr << test;
	return 0;
}