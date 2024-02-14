#include <stdio.h>
// scope i.e where the value of the variable would be available inside a program.
/* External Variable: We can share a variable in multiple C source files by using an external variable. 
 * To declare an external variable, you need to use extern keyword. 
 * When you use 'extern', the variable cannot be initialized however, it points the variable name at a storage location that has been previously defined. */
extern int myNum;//external variable (also global) //
/* Global Variable: A variable that is declared outside the function or block is called a global variable. 
 * Any function can change the value of the global variable. It is available to all the functions. 
  * Note: Declaring the storage class as global or external for all the variables in a program can waste a lot of memory space because these variables have a lifetime till the end of the program. Thus, variables, which are not needed till the end of the program, will still occupy the memory and thus, memory will be wasted.*/
int value=20;//global variable, Default initial value: 0(zero).
void function1(){ 
    // Local Variable: A variable that is declared inside the function or block is called a local variable.
    int x=10;//local variable  
    /* Static Variable: A variable that is declared with the static keyword is called static variable.
    It retains its value between multiple function calls. 
	A static variable tells the compiler to persist/save the variable until the end of program. 
	Scope of internal static variable remains inside the function in which it is defined. 
	External static variables remain restricted to scope of file in which they are declared.*/
    static int y=10;//static variable, Default initial value: 0(Zero).
    x=x+1;  
    y=y+1;  
    printf("Local=%d, Static=%d\n",x,y);  
} 
int main()
{
    int x=10;//local variable (also automatic)  
    // A variable declared inside a function without any storage class specification, is by default an automatic variable.
	// They are created when a function is called and are destroyed automatically when the function's execution is completed.
    auto int y=20;//automatic variable, Default Initial Value: Any random value i.e garbage value.
    /* The register storage class is used to define local variables that should be stored in a register instead of RAM. 
     * This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).
     * The register should only be used for variables that require quick access such as counters. 
	 * One application of register storage class can be in using loops, where the variable gets used a number of times in the program, in a very short span of time.
     * It should also be noted that defining 'register' does not mean that the variable will be stored in a register. This is because the number of registers in a CPU are limited. Also, CPU registers are meant to do a lot of important work. Thus, sometimes they may not be free. In such scenario, the variable works as if its storage class is auto. */
    register int miles=25000;//register variable, Default initial value: Any random value i.e garbage value
    printf("%d\n",miles); 
    function1();
    function1();
    function1();
    return 0;
}
/* Which storage class should be used and when
To improve the speed of execution of the program and to carefully use the memory space occupied by the variables, following points should be kept in mind while using storage classes:

* We should use static storage class only when we want the value of the variable to remain same every time we call it using different function calls.
* We should use register storage class only for those variables that are used in our program very oftenly. CPU registers are limited and thus should be used carefully.
* We should use external or global storage class only for those variables that are being used by almost all the functions in the program.
* If we do not have the purpose of any of the above mentioned storage classes, then we should use the automatic storage class. */