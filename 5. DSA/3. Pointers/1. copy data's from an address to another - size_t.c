#include <stdio.h>

void copyData(int* source, int* destination, size_t size) {
    for (size_t i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int sourceData[] = {1, 2, 3, 4, 5};
    int destinationData[5];

    size_t dataSize = sizeof(sourceData) / sizeof(sourceData[0]); //size_t is an unsigned int type of at least 16 bit

    copyData(sourceData, destinationData, dataSize);

    printf("Data copied successfully!\n");

    printf("Source Data: ");
    for (size_t i = 0; i < dataSize; i++) {
        printf("%d ", sourceData[i]);
    }
    printf("\n");

    printf("Destination Data: ");
    for (size_t i = 0; i < dataSize; i++) {
        printf("%d ", destinationData[i]);
    }
    printf("\n");

    return 0;
}