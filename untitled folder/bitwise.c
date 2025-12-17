/******************************************************************************

https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm

*******************************************************************************/
#include <stdio.h>
int count,a = 254;
int main()
{
    for(int i=0; i<8;i++){
        if((a&(1<<i)) != 0){
           count++;
        }
    }
    
    printf("%d", count);
    return 0;
}