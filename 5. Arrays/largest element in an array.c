#include<stdio.h>
#include<stdlib.h>
int main(){int a[50],size,i,big;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    printf("Enter %d elements in to the array\n", size);
    big=0;
    for(i=0;i<size;i++){scanf("%d",&a[i]);if(big<a[i])big=a[i];}
    printf("Biggest element = %d\n",big);
system("pause");}
