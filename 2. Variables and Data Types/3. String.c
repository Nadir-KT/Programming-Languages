#include<stdio.h>
#include<conio.h>
int main()
{
    char a[100];
    int i;
	char string[20] = {‘g’, ’e’, ‘e’, ‘k’, ‘s’, ‘f’, ‘o’, ‘r’, ‘g’, ’e’, ‘e’, ‘k’, ‘s’, ‘\0’};
	char string[20] = “geeksforgeeks”;
	char string [] = “geeksforgeeks”;
    printf("Enter a value : ");
    scanf("%d %s", &i, a);
    printf("Entered value : %d %s", i, a);
    getch();
}
