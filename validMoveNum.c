int inBoard(int i, int n)
{
  return (i >= 0 && i < n);
}

int in(int row, int col, int n)
{
  return (inBoard(row, n) && inBoard(col, n));
}

int empty(int row, int col, int visited[100][100])
{
  return(visited[row][col] == 0);
}

int validMoveNum(int r, int c, int n, int visited[100][100])
{
  int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

  if (!in(r, c, n))
    return -1;

  int count = 0;
  for (int i = 0; i < 8; i++) {
    int newR = r + dr[i];
    int newC = c + dc[i];
    if (in(newR, newC, n) && empty(newR, newC, visited))
      count++;
  }
  return count;
}
