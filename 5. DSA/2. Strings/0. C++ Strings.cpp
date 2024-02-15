#include <iostream>
#include <string>
using namespace std;
//The using namespace std line can be omitted and replaced with the std keyword, followed by the :: operator for string (and cout) //std::string greet;
int main() {
  string greeting1 = "\"Hello ";
  string greeting2 = "World\"";
  //C++ uses the + operator for both addition(Numbers are added) and concatenation(Strings are concatenated).
  string greeting = greeting1 + greeting2; //Concatenation
  cout << greeting <<endl;
  greeting = greeting1 + " " + greeting2;
  cout << greeting <<endl;
  string fullName = greeting1.append(greeting2); //Concatenation using append() function
  cout << fullName <<endl;
  cout << "The length of the txt string is: " << fullName.length() <<endl; //To get the length of a string, use the length() or size() function
  cout << fullName[0] <<endl; //Access characters 
  fullName[1] = 'J';
  cout << fullName <<endl;
  cout << "Type your full name: ";
  getline (cin, fullName); //Suppots space
  cout << "Your name is: " << fullName <<endl;
  string firstName;
  cout << "Type your first name: ";
  cin >> firstName; // get user input from the keyboard  //don't suppot space
  cout << "Your name is: " << firstName <<endl;
  return 0;
}