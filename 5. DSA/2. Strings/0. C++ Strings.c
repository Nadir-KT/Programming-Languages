#include <stdio.h>
#include <string.h>
int main() {
  char srting[]={};
  char greetings[] = "Hello World!";
  printf("%s", greetings);
  printf("\n%c", greetings[0]);
  greetings[0] = 'J';
  printf("\n%s\n", greetings);
  int length = sizeof(greetings) / sizeof(greetings[0]);
  for (int i = 0; i < length; ++i) {
    printf("%c", greetings[i]);
  }
  char greetings2[] = {'H', 'i', '\0'};
  // \0 "null terminating character" tells C that this is the end of the string.
  printf("\n%s\n", greetings2);
  printf("%lu\n", sizeof(greetings));   
  printf("%lu\n", sizeof(greetings2)); 
  printf("%s %s!\n", greetings2, greetings);
  char txt[] = "It\'s alright.";
  printf("%s", txt);
  printf("\n%ld", strlen(greetings));
  printf("\n%ld", sizeof(greetings));//return the memory size (in bytes), and not the actual string length
  strcat(greetings2, greetings);// Concatenate(combine) str2 to str1 (result is stored in str1)
  printf("\n%s", greetings2);
  strcpy(greetings2, txt);
  printf("\n%s", greetings2);
  printf("\n%d", strcmp(greetings2, greetings));  // Compare Strings: Returns 0 (the strings are equal)
  return 0;
}