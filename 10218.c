#include <stdio.h>
#include "findLength.h"


#define MSIZE 256

int max(int a, int b);

int main()
{
  int N;
  scanf("%d", &N);

  int matrix[MSIZE][MSIZE];
  for (int r = 0; r < N; r++)
    for (int c = 0; c < N; c++)
      scanf("%d", &(matrix[r][c]));

  int maxLength = 0;
  for (int r = 0; r < N; r++) {
    maxLength = max(maxLength, findLength(matrix, N, r, 0, 0, 1));
    maxLength = max(maxLength, findLength(matrix, N, r, 0, 1, 1));
    maxLength = max(maxLength, findLength(matrix, N, r, 0, -1, 1));
  }

  for (int c = 0; c < N; c++) {
    maxLength = max(maxLength, findLength(matrix, N, 0, c, 1, 0));
    maxLength = max(maxLength, findLength(matrix, N, 0, c, 1, 1));
  }

  for (int r = 0; r < N; r++) 
    maxLength = max(maxLength, findLength(matrix, N, r, N - 1, 1, -1));

  printf("%d\n", maxLength);
}
