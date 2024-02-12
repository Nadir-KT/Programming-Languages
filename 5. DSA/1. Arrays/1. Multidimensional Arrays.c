#include <stdio.h>

int main() {
  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
  int matrix2[][3] = { {1, 4, 2}, {3, 6, 8} }; //Compile-time initialization
  int i, j;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d\n", matrix2[i][j]);
    }
  }
  
  int arr[3][4]; //Runtime initialization
  int i, j, k;
  printf("Enter array elements:\n");
    for(i = 0; i < 3;i++)
    {
        for(j = 0; j < 4; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
           printf("%d", arr[i][j]);
        }
    }
  return 0;
}