#include<stdio.h>
#include<conio.h>
int main()
{
    int a=33,b=15,c=0;
    c=a+b; //Addition
    printf("Addition = %d\n",c);
    c=a-b; //Subtraction
    printf("Subtraction = %d\n",c);
    c=a*b; //Multiplication
    printf("Multiplication = %d\n",c);
    c=a/b; //Division
    printf("Division = %d\n",c);
    c=a%b; //Modulus
    printf("Modulus = %d\n",c);
    //a++; //Increment
    printf("Increment = %d\n",++a);
    //a--; //Decrement
    printf("Decrement = %d\n",--a);
    //Logical Operators
    c=a&&b; //Logical AND
    printf("Logical AND = %d\n",c);
    c=a||b; //Logical OR
    printf("Logical OR = %d\n",c);
    //c=!a&&b; //Logical NOT
    printf("Logical NOT = %d\n",!c);
    //Assignment Operators
    //c+=a is equivalent to c=c+a
    //c-=a is equivalent to c=c-a
    //c*=a is equivalent to c=c*a
    //c/=a is equivalent to c=c/a
    //c%=a is equivalent to c=c%a
    //c<<=2 is same as c=c<<2
    //c>>=2 is same as c=c>>2
    //c&=2 is same as c=c&2
    //c^=2 is same as c=c^2
    //c|=2 is same as c=c|2
    //Relational Operators (Comparison Operators)
    a==b //equal
    a!=b //not equal
    a>b //greater than
    a<b //less than
    a>=b //greater than or equal to
    a<=b //less than or equal to
    getch();
}
