#include <stdio.h>
 
int main()
{
    int n, c, k;
 
    printf("Enter number of rows\n");
    scanf("%d",&n);
 
    for ( c = 1; c <= n ; c++ )
    {
    	
        for( k = 1 ; k <= c ; k++ )
            {
            	printf("%d",c);
			}
            printf("%d",k);
             printf("\n");
        }

    
 
    return 0;
}

