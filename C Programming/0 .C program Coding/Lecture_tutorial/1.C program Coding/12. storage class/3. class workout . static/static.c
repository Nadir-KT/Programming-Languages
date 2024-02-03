#include<stdio.h>
void Check(); 
 int main()
 { 
     Check(); 
     Check(); 
     Check(); 
     getch();
     } 
     void Check()
     { 
          static int c=0;
           printf("%d\t",c);
            c+=5;
             } 
