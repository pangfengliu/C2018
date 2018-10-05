#include <stdio.h>

int main()
{
  int number;
  while (scanf("%d", &number) != EOF) {
#ifdef DEBUG
    printf("n %d\n", number);
#endif
    int count = 0;
    int x;
    int maxinum = -1000000;
    int mininum = 1000000;
    while (count != number) {
      if (scanf("%d", &x) == EOF)
	break;
#ifdef DEBUG
      printf("x %d\n", x);
#endif
      if (x < mininum)
	mininum = x;
      if (x > maxinum)
	maxinum = x;

      count++;
    } 
    if (count == number) {
      printf("%d\n", maxinum);
#ifdef DEBUG
      printf("complete\n");
#endif
    }
    else {
      printf("%d\n", mininum);
#ifdef DEBUG
      printf("incomplete\n");
#endif
    }
  }
  return 0;
}

			       
