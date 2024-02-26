#include <stdio.h>

// Define a sample struct
struct SampleStruct {
    int a;
    char b;
    long c;
};

int main() {
	struct SampleStruct myStruct;
    //size_t size = sizeof(myStruct);  //size_t is an unsigned int type of at least 16 bit
	//printf("Size of struct MyStruct: %zu bytes\n", size);
    // Determine the size of the struct
    printf("Size of SampleStruct: %zu bytes\n", sizeof(struct SampleStruct));
	printf("Size of struct MyStruct: %zu bytes\n", sizeof(myStruct));
	printf("Size of int a: %lu bytes\n", sizeof(myStruct.a));
	printf("Size of int a: %lu bytes\n", sizeof(myStruct.b));
	printf("Size of int a: %lu bytes\n", sizeof(myStruct.c));

    return 0;
}