#include<stdio.h>
#include<conio.h>
void binary(unsigned int);   

int main()
{
unsigned int num;
printf("Enter Decimal Number : ");
scanf("%u",&num);
binary(num);  
getch();
}
void binary(unsigned int num)
{
unsigned int mask=32768;   //mask = [1000 0000 0000 0000]
printf("Binary Eqivalent : ");

while(mask > 0)
   {
   if((num & mask) == 0 )
         printf("0");
   else
         printf("1");
  mask = mask >> 1 ;  
   }
}
