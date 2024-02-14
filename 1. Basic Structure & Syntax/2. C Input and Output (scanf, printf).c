#include <stdio.h> // printf() and scanf() functions are used for input and output
#include <stdlib.h>
#include <stdbool.h>
int main() {
	/* scanf("format specifier",&variable_name);
	&-specifes the address of the variable, don’t have to specify the reference operator (&) in cases of strings. */
	int a;
    float b;
    int x;
    double y = 0;
    char c = 0;
    char name[50];
    char srting[]={};
	printf("\"Hello World\"");
	printf("\nEnter integer and then a float: ");
    // Taking multiple inputs
    scanf("%d %f", &a, &b);
    printf("You entered %d and %f", a, b);
	printf("\nEnter a character: ");
	x = getchar(); //int getchar(void); function reads a character from the terminal and returns it as an integer.
	putchar(x); //int putchar(int character); function displays the character passed to it on the screen and returns the same character.
    printf("\nEnter a srting: ");
	//reference operator (&) is not required to scan a string
    scanf("%s", srting); //scanf() stops reading characters when it encounters a space, but gets() reads space as a character too.
    printf("Enter 2nd srting: ");
    int i = scanf("%s", name); //The scanf() function returns the number of characters read by it.
	//When working with strings in scanf(), you must specify the size of the string/array
    int j = printf("name: %s", name); //The printf() function returns the number of characters printed by it.
	printf("\nnumber of characters readed = %d",i);
    printf("\nnumber of characters printed = %d",j);
	printf("\nEnter a string: ");
    gets(srting); //char* gets(char* str); function reads a line of text from stdin(standard input) into the buffer pointed to by str pointer, until either a terminating newline or EOF (end of file) occurs. // warning: ‘gets’ is deprecated [may overflow the bounds of the buffer it was given]
    puts(srting); //int puts(const char* str); function writes the string str with a newline character ('\n') at the end to stdout. On success, a non-negative value is returned.
    fgets(srting,10,stdin); //char* fgets(char* str, int num, FILE* stream); function reads characters and stores them as a C string into str until (num-1) characters have been read or either a newline or the end-of-file is reached, whichever happens first.
    printf("The string is: %s", srting);
    printf("\nEnter another string: ");
    fgets(name,sizeof(name),stdin);
    printf("The string is: %s", name);
    return 0;
}