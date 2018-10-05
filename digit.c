#include <stdio.h>

int main()
{
  int digit;
  int count = 0;
  int zeroCount = 0;
  int evenSum = 0, oddSum = 0;
  while (scanf("%d", &digit) != EOF) {
#ifdef DEBUG
    printf("digit %d\n", digit);
#endif
    if (digit == 0)
      zeroCount++;
    if (count % 2 == 0)
      evenSum += digit;
    else
      oddSum += digit;
    count++;
  }
  printf("%d\n", count);
  if (digit % 2 == 0)		/* the last one */
    printf("1\n");
  else
    printf("0\n");
  printf("%d\n", zeroCount);
  int diff = evenSum - oddSum;
  if (diff < 0) 
    diff = -diff;
#ifdef DEBUG
  printf("evenSum %d oddSum %d diff %d\n", evenSum, oddSum, diff);
#endif
  if (diff % 11 == 0)
    printf("1\n");
  else
    printf("0\n");
    
  return 0;
}

			       
