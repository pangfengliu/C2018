#include <stdio.h>
#include <string.h>

#define STRLEN 32
int countWord(char *word)
{
  int length = strlen(word);
  int count = 0;
  for (int i = 0; i < length - 1; i++)
    if (word[i] < word[i + 1])
      count++;
  return count;
}

int countLessThan(char last, char *word)
{
  return (countWord(word) + ((last < word[0])? 1 : 0));
}

int main()
{
  char *vowel = "aeiou";
  char string[STRLEN];
  int count = 0;
  char last = 'z';
  while (scanf("%s", string) != EOF) {
    char *ptr = strtok(string, vowel);
    while (ptr != NULL) {
      count += countLessThan(last, ptr);
      last = ptr[strlen(ptr) - 1];
      ptr = strtok(NULL, vowel);
    }
  }
  printf("%d\n", count);
  return 0;
}
