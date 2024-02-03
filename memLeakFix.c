#include <stdio.h>
#include <stdlib.h>
 
void memLeakFix()
{
   int *p = (int *) malloc(sizeof(int));
 
   /* Some set of statements */
   printf("%d", p);
   
   free(p); // Free method to free the memory allocated to the pointer p to avoid memory leaks
   return; /* Return from the function freeing the pointer p*/
}

int main()
{
    memLeakFix();
    printf("Hello World");

    return 0;
}