#include <stdio.h>
#include "validMoveNum.h"
#include "nextMove.h"
int main()
{
  int n, M;
  scanf("%d%d", &n, &M);
  int row, col;
  int rowK[10000], colK[10000];
  int visited[100][100] = {0};
  for (int m = 1; m <= M; m++) {
    scanf("%d%d", &row, &col);
    visited[row][col] = 10000 * m;
    rowK[m] = row;
    colK[m] = col;
  }
  int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

  int canMove = 3;
  int count = 1 ;
  while (canMove > 0) {
    canMove = 0;
    for (int m = 0; m < M; m++) {
      int move = nextMove(rowK[m], colK[m], n, visited);
      if (move != -1) {
	int newR = rowK[m] + dr[move];
	int newC = colK[m] + dc[move];
	visited[newR][newC] = 10000 * m + count;
	rowK[m] = newR;
	colK[m] = newC;
	canMove++;
      }
    }
    count++;
  }

  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++)
      printf("%d%c", visited[r][c], c == n - 1? '\n' : ' ');

  return 0;
}
