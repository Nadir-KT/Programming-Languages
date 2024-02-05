#include<stdio.h>
#include<stdlib.h>
int main(){int r,c,i,j,a[10][10],sum;/* r - Number of rows    c - Number of Columns */
    printf("Enter the number of Rows : ");
    scanf ("%d",&r);
    printf("Enter the number of Columns : ");
    scanf ("%d",&c);
    /* Accept the Elements in m x n Matrix */
    for(i=0;i<r;i++)for(j=0;j<c;j++){printf("Enter the Element a[%d][%d] : ",i,j);scanf("%d",&a[i][j]);}
    /* Addition of all Elements */
    sum=0;
    for(i=0;i<r;i++)for(j=0;j<c;j++){sum+=a[i][j];} //sum=sum+a[i][j]
    /* Print out the Result */
    printf("The Addition of All Elements in the Matrix = %d\n",sum);
system("pause");}
