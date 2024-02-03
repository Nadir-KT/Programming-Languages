#include<stdio.h>
#include<strings.h>
main()
{
	int n;
	char name[20],age[20],temp[20],verify[5]="AyaN";

	puts("Enter verified user Name : ");
	gets(name);
	puts("Enter verified user Age : ");
	gets(age);

	n = strlen(name);
	printf("\nName Length is - %d character.\n",n);

	strcpy(temp,name);
	puts(temp);
	puts("Name Copy Completed.\n");

	strcat(name,age);
	puts(name);
	puts("Name and age join completed.\n");

	if(strcmp(verify,temp)=='\0')\
	{
		puts(name);
		puts("This user is verified.");
	}
	else
	{
		puts(name);
		puts("This user is not verified.");
	}

getch();
}
