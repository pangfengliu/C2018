#include "validMoveNum.h"
int inBoard(int i, int n);
int in(int row, int col, int n);
int empty(int row, int col, int visited[100][100]);

int nextMove(int r, int c, int n, int visited[100][100])
{
  int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  
  if (validMoveNum(r, c, n, visited) <= 0)
    return -1;

  int pMin = 1000000;
  int pMinMove;
  for (int i = 0; i < 8 ; i++) {
    int count = 0;
    int newR = r + dr[i];
    int newC = c + dc[i];

    if (in(newR, newC, n) && empty(newR, newC, visited)) {
      int p = validMoveNum(newR, newC, n, visited);
      if (p < pMin) {
	pMin = p;
	pMinMove = i;
      }
    }
  }
  return(pMinMove);
}
