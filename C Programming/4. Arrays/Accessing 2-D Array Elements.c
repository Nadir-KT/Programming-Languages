#include<stdio.h>
#include<stdlib.h>
int main()
{int i,j,a[3][3];
    for(i=0;i<3;i++)for(j=0;j<3;j++){printf("Enter the value of array element a[%d][%d] = ",i,j);scanf("%d",&a[i][j]);}
    for(i=0;i<3;i++){for(j=0;j<3;j++)printf("a[%d][%d] = %d\t",i,j,a[i][j]);printf("\n");}
    printf("Matrix Representation of Array Elements\n");
    for(i=0;i<3;i++){for(j=0;j<3;j++)printf("%d\t",a[i][j]);printf("\n");}
system("pause");}
