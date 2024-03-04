/* Dereferencing is used to access or find out the data which is contained in the memory location which is pointed by the pointer. The * (asterisk) operator which is also known as the C dereference pointer is used with the pointer variable to dereference the pointer.

Syntax for Dereferencing a Pointer
We use the indirection operator (*) as the prefix to dereference a pointer: *(pointer_name)
For modifying the data stored in the memory, we use *(pointer_name) = new_value; */

#include <iostream>
#include <string>
using namespace std;

int main() {
  string food = "Pizza";  // Variable declaration
  string* ptr = &food;    // Pointer declaration

  // Reference: Output the memory address of food with the pointer
  cout << ptr << "\n";

  // Dereference: Output the value of food with the pointer
  string a = *ptr;
  cout << a << "\n";
  return 0;
}