#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main() {
    const int x = 5 ;
    double y = 3.0;
    // x = y; // calculate the right side and store it in the left side
    y = PI;
    printf("x= %d\n",x);
    printf("y= %lf\n\n",y);
	const int c_var = 20;
	const int* const ptr = &c_var;
    /// Address of a variable
    printf("the address of y in memory is: %p ",&y); /// use '&' to get the address of a variable

    return 0;
}
