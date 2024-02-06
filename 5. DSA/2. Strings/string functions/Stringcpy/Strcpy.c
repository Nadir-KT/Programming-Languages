#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){char string1[10]= "Hello";
    char string2[10] = " Worlds";
    char string3[10] = "Bad";
    int length;
   /* copy string1 into string3 */
   strcpy(string3,string1);
   printf("strcpy(string3,string1) : %s\n",string3);
   /* concatenates string3 and string2 */
   strcat(string3,string2);
   printf("strcat(string3,string2) : %s\n",string3);
   /* total length of string3 after concatenation */
   length=strlen(string3);
   printf("strlen(string3) : %d\n",length);
system("pause");}
