/******************************************************************************
declare an array holding 3 function pointers. call 2nd  function using element of array. 

Write a function to read data from a absolute memory address that is linked to external hardware components 
(like a Watchdog Timer or Counter). For example, the memory address could be 0x12345679

Whats the issue wih this code : #include <stdio.h>
#define Init() ((void *)0)
#define ClearScrn_() printf("\033[2J\033[H");
  #define Valid_floor() { \
                 int *current_floor_ = Init(); \
          *current_floor_ = 2; \
      } 
 
int main()
{
   ClearScrn_();
   Valid_floor();
 
   return 0;
}

#include <stdio.h>
#define Init() ((void *)0)
#define ClearScrn_() printf("Hello World");
#define Valid_floor() { \
    int *current_floor_; \
    *current_floor_ = 2; \
    printf("\n%d",*current_floor_); } 
 
int main()
{
   ClearScrn_();
   Valid_floor();
 
   return 0;
}

// Online C compiler to run C program online
#include <stdio.h>
#define Init() ((void *)0)
#define ClearScrn_() printf("\033[2J\033[H");
#define Valid_floor() ({ \
        int *current_floor_; \
        *current_floor_ = 2; \
        *current_floor_; \
  } )
 
int main()
{
   ClearScrn_();
   int a = Valid_floor();
    printf("%d",a);
   return 0;
}
*******************************************************************************/
#include <stdio.h>

#define Init() ((void *)0) 
#define ClearScrn_() printf("\033[2J\033[H");
  #define Valid_floor() { \
                 int *current_floor_ = Init(); \
          *current_floor_ = 2; \
      } 
 
int main()
{
   ClearScrn_();
   Valid_floor();
   
 
   return 0;
}
