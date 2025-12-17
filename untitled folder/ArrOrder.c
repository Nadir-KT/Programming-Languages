/******************************************************************************
Write a program to sort 1st half in ascending order and the second in descending order 
Input : 11, 23, 42, 16, 83, 73, 59
Output: 11, 16, 23, 83, 73, 59, 42
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

void Order(int Input[]){
    int temp;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            if(Input[i]>Input[j]){
                temp = Input[i];
                Input[i] = Input[j];
                Input[j] = temp;
            }
        }
    }
    for(int i=3;i<7;i++){
        for(int j=i+1;j<7;j++){
            if(Input[i]<Input[j]){
                temp = Input[i];
                Input[i] = Input[j];
                Input[j] = temp;
            }
        }
    }
    for(int i=0;i<7;i++){
        printf("%d ",Input[i]);
    }
}

int main()
{
    int Input[] ={ 11, 23, 42, 16, 83, 73, 59};
    Order(Input);

    return 0;
}