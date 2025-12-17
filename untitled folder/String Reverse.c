/******************************************************************************

String Reverse

*******************************************************************************/

#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int first = 0;
    int last = strlen(str) - 1;
    char temp;

    while (first < last) {
        // Swap characters
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;

        // Move pointers towards each other
        first++;
        last--;
    }
}

int main() {
    char str[100] = "Hello World";
    reverse(str);
    printf("%s\n", str);
    return 0;
}
