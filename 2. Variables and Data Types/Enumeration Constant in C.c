#include<stdio.h>
int main() {
 enum week{ Monday =1, Tuesday, Wednesday=5, Thursday} v,h; //enum enum-name { list of names } var-list;
 v = Tuesday;
 printf("Day = %d\n", v);
 enum { A= 3, B , C , Z = 400, X, Y };
 printf("Wednesday = %d\n", Wednesday); // index value will be shown, if not Initialized and each name will be one greater than the one that precedes it.
 printf("Monday = %d\n", Monday);
 printf("B = %d \t C = %d\n", B,C);
 printf("X = %d \t Y = %d\n", X,Y);
 printf("Thursday/Tuesday = %d\n", Thursday/Tuesday);
 enum week day;
 day = Wednesday;
 printf("Day = %d\n", day);
 return 0;
}