#include <stdio.h>
#include "helper.h"

int next(int i, int a, int b, int c);
int play(int i);
int winner(int x, int y);

int main()
{
  int x, a, b, c;
  int y, d, e, f;
  int n;

  scanf("%d%d%d%d", &x, &a, &b, &c);
  scanf("%d%d%d%d", &y, &d, &e, &f);
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int count = 1;
    while (play(x) == play(y)) {
      x = next(x, a, b, c);
      y = next(y, d, e, f);
      count++;
    }
    printf("%d %d\n", winner(play(x), play(y)), count);
    x = next(x, a, b, c);
    y = next(y, d, e, f);
  }
  return 0;
}
