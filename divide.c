#include <stdio.h>

int main()
{
  int k;
  scanf("%d", &k);
#ifdef DEBUG
  printf("k %d\n", k);
#endif
  int digit;
  int count = 0;
  int prev = 0;
  int toPrint;
  while (scanf("%d", &digit) != EOF) {
#ifdef DEBUG
    printf("digit %d\n", digit);
#endif
    int value = 10 * prev + digit;
    toPrint = value / k;
    if (!(count == 0 && toPrint == 0))
      printf("%d\n", toPrint);
    prev = value % k;
    count++;
  }
  if (count == 1 && toPrint == 0)
    printf("0\n");
#ifdef DEBUG
  printf("%d\n", count);
#endif
}

			       
