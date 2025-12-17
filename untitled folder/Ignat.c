/******************************************************************************
1 2 3 4 5
1 2 3 4
1 2 3
1 2  
1

uint64_t * ptr = 4; // Always initialize pointers before use to avoid segmentation faults.
char* ptr1 = 5; 
float* ptr2= 6; 
printf("%d %d %d\n", ptr, ptr1, ptr2);
*ptr++;		// moves the pointer to the next memory location.
(*ptr)++;	// Increment value at ptr
*ptr1++;
*ptr2++;
printf("%d %d %d\n", ptr, ptr1, ptr2);
    
int main()
{
    int x[5] = { 11, 12, 13, 14, 15 };
    int* p = x;
    int i;
    int z;
    for (i = 0; i < 2; i++) {
        int z = *(p + i);
        *(p + i) = *(p + 4 - i);
        *(p + 4 - i) = z;
    }
    for (i = 0; i < 5; i++)
        printf(" %d ", x[i] );
    return 0;
}

#include <stdio.h>
#include <stdint.h>

typedef union
{
    unsigned int Var1;
    unsigned int Var2;
    uint8_t Var3;
}Test1;
int main() {
    Test1 a1;
    a1.Var3 = 2;
    a1.Var1 = 1;
    a1.Var2 = 256; // 0001 0000 0000
    printf("\n Var1 = %u, Var2 = %u Var3 = %u",a1.Var1,a1.Var2,a1.Var3); // a.Var3=0(0001 0000 0000)
    return 0;
}

*******************************************************************************/
#include <stdio.h>

void patt(void){
    static int a = 12;
    printf("%d\n",a++);
}

int main()
{
    for(int i=0;i<5;i++) patt();
    
    return 0;
}