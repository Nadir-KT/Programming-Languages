#include"conio.h"
#include"stdio.h"
#include"stdlib.h"
int main(){
    char a[50];
    int i,j;
    for(i=0;i<50;i++){a[i]=getch();if(a[i]==13){printf("%c",122);break;}else printf("*");}
    printf("\n");
    for(j=0;j<i;j++)printf("%c",a[j]);
system("pause");}
