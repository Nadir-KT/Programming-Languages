#include <iostream>
using namespace std;
// A program can have same name for local and global variables but value of local variable inside a function will take preference. 
// Global variable declaration:
int g = 20;
 
int main () {
   // Local variable declaration:
   int g = 10;
 
   cout << g;
 
   return 0;
}