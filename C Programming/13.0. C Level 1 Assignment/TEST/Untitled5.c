#include<stdio.h>
#include<string.h>

#define ASCII_A 97  // ascii for A is 97 refer www.ascii.cl
#define MAXSIZE 100 // max size for string
#define ALPHABETS 26 //total number of alphabets

int main(){

  char s[MAXSIZE];
  int a[ALPHABETS], i;
  printf("Enter the string\n");
  scanf("%s", s);

  for(i=0; i<26; i++) // initialize all array elements to zero
    a[i]=0;

  for(i=0; i<strlen(s); i++) // loop for traversing the string
    a[s[i]-ASCII_A]++; // increment by 1 for each occurrence.

  for(i=0; i< ALPHABETS; i++) //prints alphabets and occurrence.
    printf("%c %d\n", ASCII_A+i, a[i]);

  return 0;

}
