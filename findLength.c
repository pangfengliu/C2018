int in(int row, int col, int N)
{
  return (row >= 0 && row < N && col >= 0 && col < N);
}

int max(int a, int b)
{
  return (a > b? a : b);
}

int findLength (int array[][256], int N, int row, int col, int dr, int dc)
{
  int maxLength = 0;
  int length = 0;
  while (in(row, col, N)) {
    if (array[row][col] == 1)
      length++;
    else
      length = 0;
    
    row += dr;
    col += dc;
    maxLength = max(maxLength, length);
  }
  return maxLength;
}
