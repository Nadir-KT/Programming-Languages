#include <stdio.h>
int main() {
 int i, j;
 for (i = 1; i <= 5; i++) {
 printf("Outer loop iteration %d\n", i);
 for (j = 1; j <= i; j++) {
 printf(" Inner loop iteration %d x %d = %d\n",j,i,j*i);
 }
 }
 return 0;
}