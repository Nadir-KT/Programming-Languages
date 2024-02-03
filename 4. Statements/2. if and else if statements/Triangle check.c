#include<stdio.h>
#include<stdlib.h>
int main(){
    int a1,a2,a3,s;
    printf("Enter 3 Angles of the Triangle\n");
    scanf("%d%d%d",&a1,&a2,&a3);
    s=a1+a2+a3;
    if(s==180)printf("Valid Triangle\n");
    else printf("Invalid Triangle\n");
system("pause");}
