#include <iostream>
using namespace std;
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
int main()
{
    cout<<"Hello World\n";
    cout << "Hello World!" << endl;

	// initialization of variables
	int a=5;	// c-like initialization
	int b(3);	// constructor initialization
	int c{2};	// uniform initialization
	int result;	// initial value undetermined
	a = a + b;
	result = a - c;
	cout << result <<endl;
	
	const int  LENGTH2 = 10; // Defining Constant using const keyword.
	const int  WIDTH2 = 5;
	const char NEWLINE2 = '\n';

	int foo = 0;
	auto bar = 1;  // the same as: int bar = 1; 
	decltype(bar) sir;  // declared same as: int sir; 
	int* p = nullptr;
	cout << p << bar << sir <<endl;

    int myNum = 5;				// Integer (whole number without decimals)
    double myFloatNum = 5.99;	// Floating point number (with decimals)
    char myLetter = 'D';		// Character
    string myText = "Hello";	// String (text)
    bool myBoolean = true;		// Boolean (true or false)
	int a_123;					// Valid variable name
	string mystring;
	mystring = "This is the initial string content";
	mystring = "This is a different string content";
	cout << mystring <<endl;
	myText = "string expressed in \
	two lines"; //backslash (\) at the end of line is considered a line-continuation
	cout << myText <<endl;
    int x = 5, y = 6, z = 50;
    x = y = z = 50;
    cout << x + y + z;
    const int minutesPerHour = 60; //When you declare a constant variable, it must be assigned with a value
	int area = LENGTH * WIDTH;
    cout << NEWLINE;
	cout << area;
	int area2 = LENGTH2 * WIDTH2;
	cout << NEWLINE2;
	cout << area2;
    return 0;
}