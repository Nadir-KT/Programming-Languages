#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,b,no;
    printf("enter the no.");
    scanf("%d",&no);
    for(a=2;a<no;a++){if(no%a==0){b=1;break;}}
    if(b==1){printf("\n Composite number.");}
    else{printf("\n Not a Composite number.");}
system("pause");}
