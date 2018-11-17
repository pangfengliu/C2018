#include <stdio.h>
#include <string.h>

#define K 3

void merge(char *source1, char *source2, char *destination)
{
  while (*source1 != '\0' && *source2 != '\0') {
    if (strncmp(source1, source2, K) < 0) {
      strncpy(destination, source1, K);
      source1 += 3;
    } else {
      strncpy(destination, source2, K);
      source2 += 3;
    }
    destination += 3;
  }
  strcpy(destination, (*source1 == '\0')? source2 : source1);
}

#define STRLEN 100000

int main()
{
  char string1[STRLEN], string2[STRLEN];
  scanf("%s%s", string1, string2);
  char buffer[2][STRLEN];	/* for intermidiate results */
  merge(string1, string2, buffer[0]);
  printf("%s\n", buffer[0]);
  
  char *intermediate = buffer[0], *result = buffer[1];
  while (scanf("%s", string1) != EOF) {
    merge(string1, intermediate, result);
    printf("%s\n", result);
    char *temp = result;
    result = intermediate;
    intermediate = temp;
  }
}
