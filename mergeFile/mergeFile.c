#include <stdio.h>
#include <assert.h>
#include <string.h>

#define FILENAME 32

typedef struct fileHead {
  FILE *file;
  char buffer[4];
  int valid;
} FileHead;

#define N 20

typedef struct Fileheads {
  FileHead heads[N];
  int n;
} FileHeads;

void goNext(FileHead *head)
{
  int byteRead = fread(head->buffer, sizeof(char), 3, head->file);
  head->buffer[3] = '\0';
  head->valid = (byteRead == 3);
}

void initFileHead(char *filename, FileHead *head)
{
  head->file = fopen(filename, "rb");
  goNext(head);
}

int findMin(FileHeads *fileheads)
{
  int first = 1, min = -1;
  for (int i = 0; i < fileheads->n; i++) {
    FileHead *current = &(fileheads->heads[i]);
    if (current->valid) {
      if (first) {
	min = i;
	first = 0;
      } else if (strncmp(current->buffer, fileheads->heads[min].buffer, 3)
		 < 0) {
	min = i;
      }
    }
  }
  return min;
}

int main()
{
  FileHeads fileheads;
  scanf("%d", &(fileheads.n));
  char filename[FILENAME];
  for (int i = 0; i < fileheads.n; i++) {
    scanf("%s", filename);
    initFileHead(filename, &(fileheads.heads[i]));
  }

  scanf("%s", filename);
  FILE *output = fopen(filename, "wb");
  int min;
  while ((min = findMin(&fileheads)) != -1) {
    fwrite(fileheads.heads[min].buffer, sizeof(char), 3, output);
    if (min >= 0)
      goNext(&(fileheads.heads[min]));
  }

  return 0;
}
