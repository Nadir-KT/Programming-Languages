/******************************************************************************

x10000;
400Hz

GPIO toggle

2, 4, 8, 16, 32, 64, 128

12, 13 bit 30, 31 

bit banging, concatinate, check number is power of 2

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

int Pwrt(int val){
    if((((val/2)%2)==0)||val==2){
        return 1;
    }else return 0;
}

uint8_t conca(int val){
    uint8_t result;
    result=val>>29;
    result=(result<<2)|((val>>11)&3);
    return result;
}

int main()
{
    int val = 0x3001800;
    
    printf("%b\n",val);
    uint8_t result = conca(val);
    printf("%d",result);

    return 0;
}