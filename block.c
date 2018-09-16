#include <stdio.h>

int main()
{
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", n);
    int count = 0;
    int number;
    while (count < n) {
      if (scanf("%d", &number) == EOF)
	break;
      printf("number %d\n", number);
      count++;
    }
    if (count == n)
      printf("complete\n");
    else
      printf("incomplete\n");
  }
  return 0;
}
