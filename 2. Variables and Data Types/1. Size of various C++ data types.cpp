#include <iostream>
#include <limits>
using namespace std;

int main() {
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
   std::cout << "Int Min " << std::numeric_limits<int>::min() << endl;
   std::cout << "Int Max " << std::numeric_limits<int>::max() << endl;
   std::cout << "Unsigned Int  Min " << std::numeric_limits<unsigned int>::min() << endl;
   std::cout << "Unsigned Int Max " << std::numeric_limits<unsigned int>::max() << endl;
   std::cout << "Long Int Min " << std::numeric_limits<long int>::min() << endl;
   std::cout << "Long Int Max " << std::numeric_limits<long int>::max() << endl;
   std::cout << "Unsigned Long Int Min " << std::numeric_limits<unsigned  long int>::min() <<endl;
   std::cout << "Unsigned Long Int Max " << std::numeric_limits<unsigned  long int>::max() << endl;
   return 0;
}