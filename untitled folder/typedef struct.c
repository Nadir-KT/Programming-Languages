/******************************************************************************

https://www.geeksforgeeks.org/structures-c/
https://www.tutorialspoint.com/cprogramming/c_structures.htm
https://www.programiz.com/c-programming/c-structures


*******************************************************************************/
#include <stdio.h>

// defining structure
typedef struct {
    int a;
    int b;
} str;

int main()
{
    // creating structure variables using new names
    str str1;// = { 12, 10 };
    str1.a = 12;
    str1.b = 10;
    str *str2 = &str1;
    printf("%d %d", str2->a,str2->b);

    return 0;
}