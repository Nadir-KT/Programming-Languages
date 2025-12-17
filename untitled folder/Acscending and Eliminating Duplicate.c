/******************************************************************************

int arr[] = {1, 1, 2, 4, 3, 2, 4, 5};

*******************************************************************************/
#include <stdio.h>
#include <string.h>

void strRe(char str[]){
    char temp;
    for(int i=0;i<(strlen(str)/2);i++){
        temp = str[i];
        str[i] = str[strlen(str)-1-i];
        str[strlen(str)-1-i] = temp;
        //printf("%c",str[i]);
    }
}

void Acend(int *arr, int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } 
        }
    }
    printf("%d",arr[0]);
    for(int i=1;i<size;i++){
        if(arr[i-1]!=arr[i]){
            printf("%d",arr[i]);
        }
    }
}

int main()
{
    int arr[] = {1, 1, 2, 4, 3, 2, 4, 5};
    int size = sizeof(arr)/sizeof(int);
    char str[]="Hello World";
    strRe(str);
    printf("%s\n",str);
    Acend(arr,size);

    return 0;
}
