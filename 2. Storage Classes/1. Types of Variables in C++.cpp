#include <iostream>
using namespace std;
// A program can have same name for local and global variables but value of local variable inside a function will take preference. 
// Global variable declaration:
int g = 20;
int Fun(){ 
    // Local Variable: A variable that is declared inside the function or block is called a local variable.
    int x = 0;//local variable  
    /* Static Variable: A variable that is declared with the static keyword is called static variable.
    It retains its value between multiple function calls. */
    static int y = 0;//static variable  
    x++;  
    y++;  
    printf("Local=%d, Static=%d\n",x,y);  
	return x+y;
} 
int main() 
{
	// Local variable declaration:
	int g = 10;
	cout << "Value of global g is " << ::g; 
    cout<< "\nValue of local g is " << g << endl;
	
	//Auto Variables: To deduce the data type
	auto an_int = 26; 
	auto a_bool = false; 
	auto a_float = 26.24; 
	auto ptr = &a_float; 

	// Print typeid 
	cout << typeid(a_bool).name() << "\n"; 
	cout << typeid(an_int).name() << "\n"; 
	cout << typeid(ptr).name() << "\n"; 
	cout << Fun() << "\n";
	cout << Fun() << "\n";
	cout << Fun() << "\n";
	return 0; 
}