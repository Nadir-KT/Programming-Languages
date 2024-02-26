#include<stdio.h>
struct date
{
	unsigned short year: 18;	//Can store upto 2 power 12 = 4096
	unsigned short day : 5;
	unsigned short mon : 4;
	
}__attribute__((packed));
int main()
{
	struct date d;
	{
		int day,mon,year;
		printf("\n\t%d\n",sizeof(d));
	printf("\n Enter Day:month:year : ");
		 scanf("%d:%d:%d",&day,&mon,&year);
		d.day=day;
		d.mon=mon;
		d.year=year;
	}

	printf("%2d:%02d:%4d\n",d.day,d.mon,d.year);
	
}
