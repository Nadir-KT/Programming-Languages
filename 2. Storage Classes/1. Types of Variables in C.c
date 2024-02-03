#include <stdio.h>
/* External Variable: We can share a variable in multiple C source files by using an external variable. 
 * To declare an external variable, you need to use extern keyword. 
 * When you use 'extern', the variable cannot be initialized however, it points the variable name at a storage location that has been previously defined. */
extern int myNum;//external variable (also global) //
/* Global Variable: A variable that is declared outside the function or block is called a global variable. 
 * Any function can change the value of the global variable. It is available to all the functions. */
int value=20;//global variable  
void function1(){ 
    // Local Variable: A variable that is declared inside the function or block is called a local variable.
    int x=10;//local variable  
    /* Static Variable: A variable that is declared with the static keyword is called static variable.
    It retains its value between multiple function calls. */
    static int y=10;//static variable  
    x=x+1;  
    y=y+1;  
    printf("Local=%d, Static=%d\n",x,y);  
} 
int main()
{
    int x=10;//local variable (also automatic)  
    // Automatic Variable: All variables in C that are declared inside the block, are automatic variables by default.
    auto int y=20;//automatic variable 
    /* The register storage class is used to define local variables that should be stored in a register instead of RAM. 
     * This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).
     * The register should only be used for variables that require quick access such as counters. 
     * It should also be noted that defining 'register' does not mean that the variable will be stored in a register. 
     * It means that it MIGHT be stored in a register depending on hardware and implementation restrictions. */
    register int miles=25000;//register variable 
    printf("%d\n",miles); 
    function1();
    function1();
    function1();
    return 0;
}
