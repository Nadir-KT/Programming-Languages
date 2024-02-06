#include<stdio.h>
int main(){
int a[10][10],i,j,*p=&a[0][0],r,c;
printf("\n enter 2D array size::");
scanf("%d%d",&r,&c);
printf("\n enter array elements::\n");
for(i=0;i<r;i++)
for(j=0;j<c;j++)
scanf("%d",(p+i*10+j));
printf("\n displaying array elements by using the pointer::\n");
for(i=0;i<r;i++)
for(j=0;j<c;j++)
printf("%d\t",*(p+i*10+j));
}
