#include <iostream>
//using std::cout;
//using std::cin;
//using namespace std; // Using names from std( all the elements in the standard C++ library are declared within std) to avoid Naming conflicts(variables, functions, etc with the same name).
int main()
{
    std::cout << "CPP\n";
    std::cout << "Hello World!\n";
	int x, y=10;
	int sum;
	std::cout << "Type a number: ";
	std::cin >> x;
	std::cout << "Number: " << x;
	sum = x + y;
	std::cout << "\nSum is: " << sum <<std::endl;
	printf("\n%d",sum);
    return 0;
}