#include<stdio.h>

int i,j;

void show(int[][10],int,int);

main()

{

    int a[10][10],m,n;

    printf("\n enter 2d array size::");

    scanf("%d%d",&m,&n);

    printf("\n enter array elementes::");

    for(i=0;i<m;i++)

	for(j=0;j<n;j++)

	    scanf("%d",&a[i][j]);

    show(a,m,n);

    printf("\n");
}

void show(int a[][10],int m,int n)

{

    printf("\n array elements are as follows::\n");

    for(i=0;i<m;i++)

    {

	for(j=0;j<n;j++)

	    printf("%d\t",a[i][j]);

	printf("\n");
    }
}

