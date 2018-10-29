#include <stdio.h>
#include "204.h"

int main()
{
  int W, D;
  scanf("%d%d", &W, &D);
  int mirror[ROOMSIZE][ROOMSIZE];
  for (int d = D - 1; d >= 0; d--)
    for (int w = 0; w < W; w++)
      scanf("%d", &(mirror[w][d]));
  
  for (int i = 0; i < W; i++)
    trace(i, 0, 0, mirror, W, D);

  for (int i = 0; i < D; i++)
    trace(W - 1, i, 1, mirror, W, D);

  for (int i = W - 1; i >= 0; i--)
    trace(i, D - 1, 2, mirror, W, D);

  for (int i = D - 1; i >= 0; i--)
    trace(0, i, 3, mirror, W, D);
}
