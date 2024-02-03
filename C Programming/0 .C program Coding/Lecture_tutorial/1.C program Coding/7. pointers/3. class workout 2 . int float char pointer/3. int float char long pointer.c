#include<stdio.h>
 main()
{
	int a=10;
	 float b=1.5;
	 long l=77777;
	  char c='e',*cp;
	  
	   cp=&c;
	 printf("\n%c  %u", *cp,cp);	
		
	 cp=&a; 
	printf(" \n%d  %u", *cp,cp);
	
	cp=&l;
	 printf("\n%ld  %u", *cp,cp);	
	 
	 cp=&b;
		printf("\n %f  %u", *cp,cp);
	
		
}
