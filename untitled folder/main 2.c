/******************************************************************************
Inputs:
0xFFFF02FF
0xFFFF04FF
0xFFFF06FF
0xFFFF08FF
0xFFFF22FF
0xFFFF44FF
 
Outputs
0x08060402
0xFFFF4422

Write a program to sort 1st half in ascending order and the second in descending order 
Input : 11, 23, 42, 16, 83, 73, 59
Output: 11, 16, 23, 83, 73, 59, 42
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

int* Filter(int Inputs[]){
    uint8_t temp;
    static int Outputs[2]={0xFFFFFFFF, 0xFFFFFFFF};
    for(int i=5;i>=0;i--){
        if(i<4){
            Outputs[0]=Outputs[0]<<8;
            temp=Inputs[i]>>8;
            Outputs[0]|=temp;
        }else{
            Outputs[1]=Outputs[1]<<8;
            temp=Inputs[i]>>8;
            Outputs[1]|=temp;
        }
    }
    return Outputs;
}

int main()
{
    int Inputs[6]={0xFFFF02FF, 0xFFFF04FF, 0xFFFF06FF, 0xFFFF08FF, 0xFFFF22FF, 0xFFFF44FF};
    int* Outputs;
    Outputs = Filter(Inputs);
    printf("%x %x",Outputs[0],Outputs[1]);
    
    int Input[7]={11, 23, 42, 16, 83, 73, 59};
    Order(Input);
    printf("\n%d %d",Input[0],Input[1]);

    return 0;
}
