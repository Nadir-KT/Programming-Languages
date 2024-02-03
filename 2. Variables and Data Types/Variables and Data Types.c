#include<stdio.h>
#include<conio.h>
int main()
{
    int n=65;
    char c = 'A';
    float f = 23.333;
    double d = 55.5555555555555e+11;
    _Bool b = 0;
    enum Company {GOOGLE,FACEBOOK,XEROX,YAHOO=10,EBAY,MICROSOFT};
    enum Company value1 = XEROX;
    enum Company value2 = GOOGLE;
    enum Company value3 = EBAY;
    printf("Character corresponding to ASCII value %d = %c\n", n, n);
    printf("ASCII value of %c is %i\n", c, c);
    printf("ASCII value of %c is %d\n", c, c);
    printf("ASCII value of %c is %u\n", c, c);
    printf("Float Variable : %f\n", f);
    printf("Double Variable : %e\n", d);
    printf("Double Variable : %g\n", d);
    printf("Boolean Variable : %i\n", b);
    printf("Boolean Variable : %d\n", b);
    printf("Boolean Variable : %u\n", b);
    printf("Boolean Variable : %x\n", b);
    printf("Boolean Variable : %o\n", b);
    printf("The value of xerox is : %i\n", value1);
    printf("The value of google is : %d\n", value2);
    printf("The value of ebay is : %u\n", value3);
    getch();
}
