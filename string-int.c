#include <stdio.h>
#include <string.h>

#define CHARPERINT 8
#define BITPERCHAR 8
#define STRLEN 100000

int min(int a, int b)
{
  return (a < b? a : b);
}

unsigned long long string2int(char *string)
{
  unsigned long long int sixtyfour = 0;
  int length = strlen(string);

  for (int i = 0; i < CHARPERINT; i++) {
    sixtyfour <<= BITPERCHAR;
    if (i < length)		/* we do not know what is behind \0 */
      sixtyfour |= string[i];
  }
  return sixtyfour;
}

void string2ints(void)
{
  char string[STRLEN], *strptr = string;
  scanf("%s", string);
  int numInt = (strlen(string) + CHARPERINT) / CHARPERINT;
  for (int i = 0; i < numInt; i++, strptr += CHARPERINT)
    printf("%llu\n", string2int(strptr));
}

char getMSB(unsigned long long int sixtyfour)
{
  return (sixtyfour >> (64 - BITPERCHAR) & 0xFF);
}

void ints2string()
{
  char string[STRLEN] = {0}, *strptr = string;
  int num;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    unsigned long long int sixtyfour;
    scanf("%llu", &sixtyfour);
    for (int j = 0 ; j < CHARPERINT; j++, strptr++) {
      *strptr = getMSB(sixtyfour);
      sixtyfour <<= CHARPERINT;
      if (*strptr == '\0')
	break;
    }
  }
  printf("%s\n", string);
}

#define STRING2INT 0
#define INT2STRING 1

int main()
{
  int type;
  scanf("%d", &type);
  switch (type) {
  case STRING2INT:
    string2ints();
    break;
  case INT2STRING:
    ints2string();
  }
  return 0;
}
