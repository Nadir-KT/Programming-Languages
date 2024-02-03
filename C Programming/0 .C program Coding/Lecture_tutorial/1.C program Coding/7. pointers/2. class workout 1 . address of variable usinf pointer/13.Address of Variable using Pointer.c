#include<stdio.h>
int main( )
{
int i = 3 ;
printf("nAddress of i = %u", &i ) ;
printf("nValue of i = %d", i ) ;
printf("nValue of i = %d", *( &i ) ) ;
getch();
}
