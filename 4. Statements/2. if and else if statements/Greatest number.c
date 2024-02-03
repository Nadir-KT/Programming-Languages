#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,b,c,Big=0;
    printf("Enter 3 Numbers\n");
    scanf("%d %d %d",&a,&b,&c);
    if((a>b)&&(a>c)) Big=a;
    else if((b>a)&&(b>c)) Big=b;
    else Big=c;
    printf("%d is greatest\n",Big);
system("pause");}
