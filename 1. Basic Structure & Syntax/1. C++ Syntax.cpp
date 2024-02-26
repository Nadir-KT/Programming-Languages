// single-line comment
/* multi-line comment */
#include <iostream> //includes the standard input output library functions. It provides cin and cout methods for reading from input and writing to output respectively.
#include<conio.h> //includes the console input output library functions. The getch() function is defined in conio.h file.
using namespace std;
int main() //The main() function is the entry point of every program in C++ language. The void keyword specifies that it returns no value.
{
	cout << "Hello World!" << endl;
	getch(); //The getch() function asks for a single character. Until you press any key, it blocks the screen.
	return 0;
}
