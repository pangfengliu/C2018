#include <stdio.h>
#include "conversion.h"
#include <assert.h>
#include <string.h>

void bin2ascii(char inputFile[32], char outputFile[32], char dictionary[17])
{
  FILE *input = fopen(inputFile, "rb");
  FILE *output = fopen(outputFile, "wb");
  assert(input != NULL);
  assert(output != NULL);
  
  char inBuffer;
  while (fread(&inBuffer, sizeof(char), 1, input) != 0) {
    char outBuffer[2];
    outBuffer[0] = dictionary[(inBuffer >> 4) & 0xf];
    outBuffer[1] = dictionary[inBuffer & 0xf];
    fwrite(outBuffer, sizeof(char), 2, output);
  }
  fclose(input);
  fclose(output);
}

void ascii2bin(char inputFile[32], char outputFile[32], char dictionary[17])
{
  FILE *input = fopen(inputFile, "rb");
  FILE *output = fopen(outputFile, "wb");
  assert(input != NULL);
  assert(output != NULL);
  
  char inBuffer[2];
  while (fread(inBuffer, sizeof(char), 2, input) != 0) {
    char outBuffer;
    outBuffer = (((strchr(dictionary, inBuffer[0]) - dictionary) << 4) |
		 (strchr(dictionary, inBuffer[1]) - dictionary));
    fwrite(&outBuffer, sizeof(char), 1, output);
  }
  fclose(input);
  fclose(output);
}
