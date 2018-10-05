#include <stdio.h>

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
#ifdef DEBUG
  printf("n %d m %d\n", n, m);
#endif
  int x = 0, y = 0;
  printf("%d\n%d\n", x, y);
  int command;
  while (scanf("%d", &command) != EOF) {
    int newx = x, newy = y;
#ifdef DEBUG
    printf("%d\n", command);
#endif
    int reminder = command % 5;
    switch (reminder) {
    case 1:
      newx += command;
      break;
    case 2:
      newx -= command;
      break;
    case 3:
      newy += command;
      break;
    case 4:
      newy -= command;
      break;
    }
    if (command % 5 != 0 && (newx >= 0 && newx < n && 
			     newy >= 0 && newy < m)) {
      x = newx;
      y = newy;
      printf("%d\n%d\n", x, y);
    }
  }
  return 0;
}
