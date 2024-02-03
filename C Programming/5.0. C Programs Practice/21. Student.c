#include<stdio.h>
main()
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
	if(mat>=35 && phy>=35 && che>=35 )
	{
    	    if(avg>=75)			// This if else ladder finds Grade of the student
		printf("\n Distinction\n");
	    else if(avg>=60)
		printf("\n First Class\n");
	    else if(avg>=50)
		printf("\n Second Class\n");
	    else if(avg>=35)
		printf("\n Third  Class\n");
	}
	else
		printf("\n Fail \n");
}




