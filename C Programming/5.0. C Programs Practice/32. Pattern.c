#include<stdio.h>
int main()
{
    int r,c,l=5;
	//printf("Enter number of lines : ");
	//scanf("%d",&l);
    for(r=1;r<=l;r++)
        {
            for(c=1;c<=r;c++)
                {
                        printf(" ");
                }
            for(c=1;c<=2*(l-r)+1;c++)
                {
                        printf("*");
                }
            printf("\n");
        }
system("pause");
}
