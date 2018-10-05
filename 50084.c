#include <stdio.h>

#define MAXJ 500
#define MAXM 500
#define MAXTPERJOB 500

int main()
{
  int Mready[MAXM] = {0};
  int Jready[MAXJ];
  int machine[MAXJ][MAXTPERJOB];
  int time[MAXJ][MAXTPERJOB];
  int numTask[MAXJ];
  int currentTask[MAXJ] = {0};
  int taskTotal = 0;
  int M, J;
  scanf("%d%d", &M, &J);
#ifdef DEBUG
  printf("M %d J %d\n", M, J);
#endif
  for (int j = 0; j < J; j++) {
    scanf("%d%d", &(Jready[j]), &(numTask[j]));
#ifdef DEBUG
    printf("ready %d num %d\n", Jready[j], numTask[j]);
#endif
    for (int t = 0; t < numTask[j]; t++) {
      scanf("%d%d", &machine[j][t], &time[j][t]);
#ifdef DEBUG
      printf("m %d t %d\n", machine[j][t], time[j][t]);
#endif
    }
    taskTotal += numTask[j];
  }
#ifdef DEBUG
  printf("total task = %d\n", taskTotal);
#endif

  for (int t = 0; t < taskTotal; t++) {
    int earliest = 2147483647;
    int earliestJob, earliestMachine;
    int completion;
    for (int j = 0; j < J; j++) {
      if (currentTask[j] < numTask[j]) {
	int nextMachine = machine[j][currentTask[j]];
	int ready;
	if (Mready[nextMachine] > Jready[j])
	  ready = Mready[nextMachine];
	else
	  ready = Jready[j];
	completion = ready + time[j][currentTask[j]];
	if (completion < earliest) {
	  earliest = completion;
	  earliestJob = j;
	  earliestMachine = nextMachine;
	}
      }
    }
#ifdef DEBUG
    printf("job %d completes at %d is earliest\n", 
	   earliestJob, completion);

    Jready[earliestJob] = earliest;
    Mready[earliestMachine] = earliest;
    currentTask[earliestJob]++;
  }
  for (int j = 0; j < J; j++)
    printf("%d\n", Jready[j]);
  return 0;
}
