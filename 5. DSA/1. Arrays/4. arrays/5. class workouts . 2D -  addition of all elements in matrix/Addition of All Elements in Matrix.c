#include<stdio.h>
#include<conio.h>

int main()
{
int i,j,a[10][10],sum,m,n;

/* m - Number of rows 
   n - Number of Columns */

printf("nEnter the number of Rows : ");
scanf ("%d",&m);

printf("nEnter the number of Columns : ");
scanf ("%d",&n);

/* Accept the Elements in m x n Matrix */

for(i=0;i<m;i++)
       for(j=0;j<n;j++ )
       {
       printf("Enter the Element a[%d][%d] : ", i , j);
       scanf("%d",&a[i][j]);
       }

/* Addition of all Elements */

sum = 0;

for(i=0;i<m;i++ )
       for(j=0;j<n;j++ )
       {
       sum = sum + a[i][j];
       }

/* Print out the Result */
printf("nThe Addition of All Elements in the Matrix : %d",sum);
getch();
}
