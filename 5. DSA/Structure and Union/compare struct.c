#include <stdio.h>  // Include necessary header for input/output functions

struct data {
    int a;
    char b;
    int c;
    char d;
};

int main() {  // Add a main function for correct execution
    struct data pass = {3, 'e', 2, 'g'};  // Initialize struct members directly
    struct data enteredpass;

    printf("Enter password (four values separated by spaces): ");  // Prompt for input
    scanf("%d %c %d %c", &enteredpass.a, &enteredpass.b, &enteredpass.c, &enteredpass.d);  // Read all values in a single scanf

    if ((enteredpass.a == pass.a) && (enteredpass.b == pass.b) && (enteredpass.c == pass.c) && (enteredpass.d == pass.d)) {
        printf("Login success\n");  // Add newline for better formatting
    } else {
        printf("Incorrect password\n");  // Add newline for better formatting
    }

    return 0;  // Indicate successful program termination
}