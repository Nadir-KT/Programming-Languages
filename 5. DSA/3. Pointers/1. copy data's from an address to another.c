#include <stdio.h>

int main() {

  int values[5] = {10, 20, 30, 40, 50}; // array of 5 values
  int *ptr1 = values; // pointer to values array
  // The name of an array, is actually a pointer to the first element of the array.
  int copied[5]; 
  int *ptr2 = copied; // pointer to copied array

  // Copy values from ptr1 to ptr2
  for(int i=0; i<5; i++) {
    *(ptr2 + i) = *(ptr1 + i);
  }

  // Print arrays
  printf("Original Array: ");
  for(int i=0; i<5; i++) {
    printf("%d ", *(ptr1 + i)); 
  }
  
  printf("\nCopied Array: ");
  for(int i=0; i<5; i++) {
    printf("%d ", *(ptr2 + i));
  }

  return 0;
}