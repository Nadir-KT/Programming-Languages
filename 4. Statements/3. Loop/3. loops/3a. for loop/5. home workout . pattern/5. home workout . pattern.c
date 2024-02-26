main()
{
int n, c, k, space, count =1;
 
printf("Enter number of rows\n");
scanf("%d",&n);
 
space= n;
 
for( i =1; i <= n ;i++)
{
for( j =1; j < space ; j++)
printf(" ");
 
for( j =1; j <= i ; j++)
{
printf("*");


}
 
printf("\n");
space--;
count=1;
}
return 0;
}

