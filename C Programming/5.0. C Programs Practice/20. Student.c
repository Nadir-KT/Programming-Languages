#include<stdio.h>
int main()
{
	int roll,mat,phy,che,tot;
	float avg;
	printf("\n Enter student Details \n ");
	printf("\n Enter Student Roll no : ");
	 scanf("%d",&roll);
	printf("\n Enter marks in Maths : ");
	 scanf("%d",&mat);
	printf("\n Enter marks in Physics : ");
	 scanf("%d",&phy);
	printf("\n Enter marks in Chemistry : ");
	 scanf("%d",&che);
	tot = mat+phy+che;
	avg = (float) tot/3;
	printf("\n Total : %d\n Average : %.2f\n",tot,avg);
	if(mat>=40 && phy>=40 && che>=40)
		printf("\n Pass \n");
	else
		printf("\n Fail \n");
}
