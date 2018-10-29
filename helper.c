int next(int i, int a, int b, int c) 
{
  return ((i * a + b) % c);
}

int play(int i)
{
  return (i % 3);
}

int winner(int x, int y)
{
  return ((x + 3 - y) % 3 == 1? 0 : 1);   /* 2 > 1 > 0 > 2 */
}
