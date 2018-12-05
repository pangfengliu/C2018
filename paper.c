#include <stdio.h>

typedef struct paper {
  int width;
  int height;
} Paper;

typedef struct solution {
  int layer;
  int sum;
} Solution;

int onTop(Paper a, Paper b)
{
  return (((a.width <= b.width) && (a.height <= b.height) ||
	   ((a.width <= b.height) && (a.height <= b.width)))? 1 : 0);
}

Solution better(Solution a, Solution b)
{
  return (((a.layer > b.layer) ||
	   ((a.layer == b.layer) && a.sum > b.sum))? a : b);
}

Solution bestSolution(int index, int n, Paper top, Paper papers[],
		      Solution solution)
{
  if (index >= n)
    return solution;
  if (onTop(papers[index], top)) {
    Solution placed = solution;
    placed.layer += 1;
    placed.sum += index;
    return better(bestSolution(index + 1, n, papers[index], papers, placed),
		  bestSolution(index + 1, n, top, papers, solution));
  } else
    return bestSolution(index + 1, n, top, papers, solution);
}

int main()
{
  int n;
  scanf("%d", &n);
  Paper papers[n];
  for (int i = 0; i < n; i++)
    scanf("%d%d", &(papers[i].width), &(papers[i].height));

  Solution zero = {0, 0};
  Paper bottom = {10000, 10000};
  Solution best = bestSolution(0, n, bottom, papers, zero);
  printf("%d %d\n", best.layer, best.sum);
  return 0;
}
