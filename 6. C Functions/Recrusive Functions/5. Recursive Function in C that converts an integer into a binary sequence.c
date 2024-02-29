/******************************************************************************
Enter a number: 345
Binary representation: 100110101
Enter a number: 345
Binary representation: 101011001

345%2=1
172%2=0
86%2=0
43%2=1
21%2=1
10%2=0
5%2=1
2%2=0
1%2=1
*******************************************************************************/
#include <stdio.h>

void printBinary(int num) {
    if (num > 1) {
        printBinary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Binary representation: ");
    printBinary(num);
    return 0;
}