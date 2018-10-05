#include <stdio.h>

int main()
{
  int number;
  int max = 0;
  int right = -1;		/* will be differnt from anyone */
  int length;			/* should be set by the first number */

  while (scanf("%d", &number) != EOF) {
    int digits = 1;
    int left = number;
    while (left >= 10) {
      left /= 10;
      digits++;
    }
    if (left == right) 
      length += digits;
    else
      length = digits;

    if (length > max)
      max = length;

    right = (number % 10);
  }
  printf("%d\n", max);
  return 0;
}
