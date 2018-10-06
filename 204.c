#include <stdio.h>

int main()
{
  int W, D;
  scanf("%d%d", &W, &D);
  int mirror[W][D];
  for (int d = D - 1; d >= 0; d--)
    for (int w = 0; w < W; w++)
      scanf("%d", &(mirror[w][d]));
  
  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};
  int newDir[4] = {3, 2, 1, 0};
  
  int x, y, dir;
  for (int i = 0; i < 2 * (W + D); i++) {
    if (i < W) {
      x = i; y = 0; dir = 0;	/* up */
    } else if (i < W + D) {
      x = W - 1; y = i - W; dir = 1; /* left */
    } else if (i < 2 * W + D) {
      x = W - (i - (W + D)) - 1; y = D - 1; dir = 2; /* down */
    } else {
      x = 0; y = D - (i - (D + 2 * W)) -1; dir = 3; /* right */
    }
    while (x >= 0 && x < W && y >= 0 && y < D) {
      if (mirror[x][y] == 1) 
	dir = newDir[dir];
      x += dx[dir];
      y += dy[dir];
    }
#ifdef  DEBUG
    printf("x %d, y %d\n", x, y);
#endif
    if (y < 0)
      printf("%d\n", x);
    else if (x >= W)
      printf("%d\n", W + y);
    else if (y >= D)
      printf("%d\n", W + D + (W - x) - 1);
    else
      printf("%d\n", 2 * W + D + (D - y) - 1);
  }
}
