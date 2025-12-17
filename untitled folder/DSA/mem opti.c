#include <stdint.h>
#include <stdio.h>

// Define enum
enum Color {
    RED,
    GREEN,
    BLUE
};

// Define structure
struct Point {
    int x;
    int y;
};

// Define union
union Data {
    int intValue;
    float floatValue;
};

// Define an array of uint64_t
uint64_t QuadWordRead[4];

// Populate the QuadWordRead array with values from enum, structure, and union
void populateQuadWordRead() {
    // Store enum values
    QuadWordRead[0] = (uint64_t)RED;
    QuadWordRead[1] = (uint64_t)GREEN;
    QuadWordRead[2] = (uint64_t)BLUE;

    // Store structure values
    struct Point point = {10, 20};
    QuadWordRead[3] = *((uint64_t *)&point);

    // Store union values
    union Data data;
    data.intValue = 42;
    QuadWordRead[4] = (uint64_t)data.intValue;
}

int main() {
    populateQuadWordRead();

    // Print the values stored in the QuadWordRead array
    printf("QuadWordRead array:\n");
    for (int i = 0; i < 4; i++) {
        printf("%llu\n", QuadWordRead[i]);
    }

    return 0;
}
