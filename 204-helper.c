#include <stdio.h>
#include "204.h"

int xy2index(int x, int y, int W, int D)
{
  if (y < 0)
    return(x);
  else if (x >= W)
    return(W + y);
  else if (y >= D)
    return(W + D + (W - x) - 1);
  else
    return(2 * W + D + (D - y) - 1);
}

void trace(int x, int y, int dir, int mirror[ROOMSIZE][ROOMSIZE], int W, int D)
{
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int newDir[4] = {3, 2, 1, 0};

  while (x >= 0 && x < W && y >= 0 && y < D) {
    if (mirror[x][y] == 1) 
      dir = newDir[dir];
    x += dx[dir];
    y += dy[dir];
  }
  printf("%d\n", xy2index(x, y, W, D));
}
