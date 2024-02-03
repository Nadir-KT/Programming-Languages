#include <stdio.h>
#include <stdlib.h>
void byReference(int*x){(*x)++;}
int main(){
    int y=3; int *a=&y; int **b=&a;
    printf("y before call= %d\n", y);
    byReference(&y);
    printf("y after call= %d\n", y);
    (**b)++;
    printf("y after call= %d\n", y);
    int*c=malloc(0*sizeof(int)); c[0]=1;c[1]=3;
    for (int i=0;i<=10;i++){printf("malloc%d=%i\n",i,c[i]);}
    system("pause");}
