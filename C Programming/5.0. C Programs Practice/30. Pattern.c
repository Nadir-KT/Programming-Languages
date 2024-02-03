#include<stdio.h>
int main()
{
    int r,c,count=1;
    for(r=1;r<=5;r++) //rows
        {
            for(c=1;c<=r;c++) //columns
                {
                        printf("%d ",count);
						count++;
                }
            printf("\n");
        }
system("pause");
}
