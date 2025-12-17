const char* myString = "12345678";
uint64_t value = strtoull(myString, NULL, 10);
QuadWordRead[0] = value;


#include <stdint.h>
#include <stdio.h>

int main() {
    // Define an array of pointers to uint64_t
    uint64_t* QuadWordRead[4];

    // Define and initialize a string
    const char *myString = "Hello, world!";

    // Convert the string to an array of uint64_t pointers
    uint64_t *stringPtr = (uint64_t *)myString;

    // Store the address of the string in each element of the array
    for (int i = 0; i < 4; i++) {
        QuadWordRead[i] = stringPtr;
    }

    // Print the values stored in the QuadWordRead array
    printf("QuadWordRead array:\n");
    for (int i = 0; i < 4; i++) {
        printf("%p\n", (void *)QuadWordRead[i]);
    }

    return 0;
}
