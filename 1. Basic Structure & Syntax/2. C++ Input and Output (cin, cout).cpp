#include <iostream>
//using std::cout;
//using std::cin;
using namespace std; // Using names from std( all the elements in the standard C++ library are declared within std) to avoid Naming conflicts(variables, functions, etc with the same name).
int main()
{
    cout << "CPP\n";
    cout << "Hello World!\n";
	int x, y=10;
	int sum;
	cout << "Type a number: ";
	cin >> x;
	cout << "Number: " << x;
	sum = x + y;
	cout << "\nSum is: " << sum <<endl;
	printf("\n%d",sum);
    return 0;
}