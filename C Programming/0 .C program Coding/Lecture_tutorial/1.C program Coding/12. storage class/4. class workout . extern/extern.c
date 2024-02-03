#include<stdio.h>
#include<conio.h> 
void Check(); 
int a=5;
 int main()
 {
      a+=4; 
      Check(); 
      //return 0; 
      getch();
      }
       void Check()
       { ++a;
        printf("a=%d\n",a); 
        }
