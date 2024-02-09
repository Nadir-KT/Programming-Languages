#include<stdio.h>
#include<conio.h>
main()
{
      int a,b,c,Big=0;
      printf("enter 3 numbers");
      scanf("%d %d %d",&a,&b,&c);
      if((a>b)&&(a>c))
	  {
	  	Big=a;
	  }
      else if((b>a)&&(b>c))
	  {
	  	Big=b;
	  }
    	else
    	{
    		Big =c;
		}
    	
          
		printf("%d is greatest",Big);
        
      getch();
      }
      
