#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a=30,b=20;
	printf("%d %d\n",a,b);
	printf("add- %d\n",a+b);
	printf("sub- %d\n",a-b);
	printf("mul- %d\n",a*b);
	printf("div- %d\n",a/b);
	printf("mod- %d\n",a%b);
    /// assignment operator
    a = 0;
    b = 2;
    a = b;
    printf("a= %d b= %d\n\n", a, b);

    /// arithmetic operators +  -  *  /  %
    int x = 2;
    int y = 3;
    int sum = x + y; /// addition
    printf("sum: %d\n", sum);
    printf("subtraction: %d\n", x-y); /// subtraction
    printf("multiplication: %d\n", x*y);
    printf("remainder: %d\n", x%y);
    printf("remainder: %d\n\n", y%x);

    printf("5/2 (lf): %lf\n", 5/2);
    printf("5/2 (d): %d\n", 5/2);
    printf("5.0/2: %lf\n", 5.0/2);
    printf("x/y (d): %d\n", x/y);
    printf("x/y (casting): %lf\n\n",  x/(double) y); /// casting x to a double

    /// compound assignment operator
    a += 2; /// a = a+2;
    printf("a= %d\n",a);

    a *=2+b; /// a = a* (2+b)
    printf("a= %d\n\n",a);

    /// increment ++ (same for decrement --)
    int i = 0;
    printf("%d\n",i);
    i = i +1; /// 1
    printf("%d\n",i);
    i++; /// 2
    printf("%d\n",i);
    ++i; /// 3
    printf("%d\n",i);
    printf("%d\n", i++); /// prints the current value of i (3) then does the increment (i=4) [post-increment]
    printf("%d\n",i);
    printf("%d\n\n",++i); /// does the increment (i=5) then prints the value of i (5) [pre-increment]

    int h = i++; /// assigns the current value of i (5) to h then increments i (i=6)
    printf("h= %d i= %d\n", h, i);
    int k = ++i; /// increments i (i=7) then assigns the value (7) to k
    printf("k= %d i= %d\n\n", k, i);

    /// the same goes for the decrements but instead we subtract 1

    /// relational operators ==   !=   >   <   >=   <=
    printf("1==1: %d\n",1==1);
    printf("1!=1: %d\n",1!=1);
    printf("1>1: %d\n",1>1);
    printf("1>=1: %d\n",1>=1);
    printf("2>=1: %d\n",2>=1);
    printf("1<1: %d\n",1<1);
    printf("1<=1: %d\n\n",1<=1);

    /**
    // logical operators
    && (and): true when both conditions are true, false otherwise
     || (or): true when at least one condition is true, false when both conditions are false
     ! (not): !true=false, !false=true
    */
    printf("1==1 && 2==2 (both are true): %d\n",!(1==1 && 2==2));
    printf("1==1 && 2!=2 (one is false): %d\n",1==1 && 2!=2);
    printf("1!=1 && 2!=2 (both are false): %d\n\n",1!=1 && 2!=2);

    printf("1==1 || 2==2 (both are true): %d\n",1==1 || 2==2);
    printf("1==1 || 2!=2 (one is true): %d\n",1==1 || 2!=2);
    printf("1!=1 || 2!=2 (both are false): %d\n\n",1!=1 || 2!=2);

    int o = 1, p = 1; /// initializing two variables of the same type
    printf("you can join as many conditions as you want: %d\n\n", (1==2 && 1!=2) || (o==p && o==1));

    /// sizeof operator
    printf("int: %d\n", sizeof o);
    printf("int: %d\n", sizeof(o));
    printf("int: %d\n", sizeof(int));
    printf("double: %d\n", sizeof(double));
    printf("char: %d\n\n", sizeof(char));

    /// operator precedence
    printf("operator precedence: %d", o + p - (o * 3) + (4 / 2)); /// o + p - (o*3) + (4/2) = 1+1-3+2 = 1
	
	/// comma(,) precedence
	a = 5; 
	b = 10; 
	int c = (a++, b++, a + b);
	printf("\nc = %d", c);
	
	// . (dot) operator is used to access individual elements of a C structure or C union.	
	// If emp is a structure with an element int age in it, then emp.age will return the value of age.
	
	// -> (arrow) operator	used to access structure or union elements using a pointer to the structure or union.
	// If p is a pointer to the emp structure, then we can access age element using p->age
	
	int arr[3] = {1, 2, 3};
	int *ptr = arr;
	printf("\n%d", *ptr);     // prints 1
	ptr++;
	printf("\n%d\n", *ptr);     // prints 2
	
	int myAge = 25;
	int votingAge = 18;
	printf("%d", myAge >= votingAge); // Returns 1 (true), meaning 25 year olds are allowed to vote!
	return 0;
}