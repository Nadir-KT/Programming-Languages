/* Program to print prime factors*/
#include<stdio.h>
void PFactors(int num);
void IPFactors(int n);
int main(void)
{
	int num;
	printf("Enter a number : ");
	scanf("%d", &num);
	PFactors(num);	printf("\n");
	IPFactors(num);	printf("\n");
	return 0;
}/*End of main()*/

void PFactors(int num)
{
	int i=2;
	if(num==1)
		return;
	while(num%i!=0)
		i++;
	printf("%d ", i);
	PFactors(num/i);
}/*End of PFactors()*/

/*Iterative*/
void IPFactors(int num)
{
	int i;
	for(i=2; num!=1; i++)
		while(num%i == 0)
		{
			printf("%d ",i);
			num = num/i;
		}
}/*End of IPFactors()*/
