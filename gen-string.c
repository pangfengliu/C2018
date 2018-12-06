#include <stdio.h>

void genString(char string[], int i, int K, int L, int N, int *count);
  
void genStringFromTo(char from, char to,
		     char string[], int i, int K, int L, int N, int *count)
{
  for (char c = from; c <= to; c++) {
    string[i] = c;
    genString(string, i + 1, K, L, N, count);
  }
}

void genString(char string[], int i, int K, int L, int N, int *count)
{
  if (*count == N)
    return;
  if (i >= L) {
    printf("%s\n", string);
    *count += 1;
    return;
  }
  char last = string[i - 1];
  if (last + K <= 'z')
    genStringFromTo(last + 1, last + K, string, i, K, L, N, count);
  else {
    int first = 'z' - last;
    int second = K - first;
    genStringFromTo('a', 'a' + second - 1, string, i, K, L, N, count);
    genStringFromTo('z' - first + 1, 'z', string, i, K, L, N, count);
  }
}

int main()
{
  char C[2];
  int K, L, N;
  scanf("%s%d%d%d", C, &K, &L, &N);
  char string[L + 1];
  string[0] = C[0];
  string[L] = '\0';
  int count = 0;
  genString(string, 1, K, L, N, &count);
}
