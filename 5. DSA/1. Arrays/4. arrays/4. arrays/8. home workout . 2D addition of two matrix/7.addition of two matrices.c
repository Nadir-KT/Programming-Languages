#include<stdio.h>
#include<conio.h>

int main()
{
int i,j,a[10][10],b[10][10],c[10][10],m1,n1,m2,n2;

/* m - Number of rows
   n - Number of Columns */


printf("nEnter the number of Rows of Mat1 : ");
scanf ("%d",&m1);

printf("nEnter the number of Columns of Mat1 : ");
scanf ("%d",&n1);

/* Accept the Elements in m x n Matrix */

for(i=0;i<m1;i++)
    for(j=0;j<n1;j++)
    {
    printf("Enter the Element a[%d][%d] : ",i,j);
    scanf("%d",&a[i][j]);
    }

// ------------------------------------------

printf("nEnter the number of Rows of Mat2 : ");
scanf ("%d",&m2);

printf("nEnter the number of Columns of Mat2 : ");
scanf ("%d",&n2);

/* Before accepting the Elements Check if no of
   rows and columns of both matrices is equal */

if ( m1 != m2 || n1 != n2 )
 {
 printf("nOrder of two matrices is not same ");
 exit(0);
 }

 // ------ Terminate Program if Orders are unequal
 // ------ exit(0) : 0 for normal Termination

/* Accept the Elements in m x n Matrix */

for(i=0;i<m2;i++)
    for(j=0;j<n2;j++)
    {
    printf("Enter the Element b[%d][%d] : ",i,j);
    scanf("%d",&b[i][j]);
    }

// ------------------------------------------

/* Addition of two matrices */

for(i=0;i<m1;i++)
    for(j=0;j<n1;j++)
    {
    c[i][j] = a[i][j] + b[i][j] ;
    }

/* Print out the Resultant Matrix */

printf("nThe Addition of two Matrices is : ");

for(i=0;i<m1;i++)
 {
    for(j=0;j<n1;j++ )
    {
    printf("%d\t",c[i][j]);
 }
}

getch();
}
