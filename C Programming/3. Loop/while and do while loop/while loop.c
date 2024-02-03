#include<stdio.h>
#include<stdlib.h>
int main(){int i=10;
    while(i>=0){printf("Counter is %i\n",i);i--;/** i=i+1 */}
    int x=1;
    while(x){i=0;while(i<10){printf("i is %d\n",i);i++;x=0;/** break; */}printf("x is %i\n",x);}
system("pause");}
