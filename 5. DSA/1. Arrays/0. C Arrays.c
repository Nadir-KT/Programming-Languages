#include <stdio.h>

int main() {
  int myNumbers[] = {25, 50, 75, 100};
  myNumbers[0] = 33; // Change the value of a specific element
  int length = sizeof(myNumbers) / sizeof(myNumbers[0]); //Get Array Size or Length
  int i;
  // Loop Through an Array
  for (i = 0; i < 4; i++) {
    printf("%d\n", myNumbers[i]);
  }
  // Create a variable and assign the first array element of ages to it
  int lowestNumber = myNumbers[0];

  // Loop through the elements of the ages array to find the lowest age
  for (int i = 0; i < length; i++) {
    if (lowestNumber > myNumbers[i]) {
      lowestNumber = myNumbers[i];
    }
  }
  printf("%d\n", lowestNumber);
  return 0;
}