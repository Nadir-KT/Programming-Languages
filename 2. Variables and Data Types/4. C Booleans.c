#include <stdio.h>
#include <stdbool.h>
int main()
{

    bool submitted[5] = {'0', '1', '1', '0', '1'};

    printf("Submission details are:\n");
    for(int i = 0; i < 5; i++)
        printf("%d : %d\n",i + 1, submitted[i]);
    return 0;
}