#include <stdio.h>
#include <stdlib.h>
#include "../include/string-utils.h"

int main()
{
  FILE *fptr = fopen("./day2/data.txt", "r");
  if (fptr == NULL)
  {
    printf("Not able to open the file.");
    exit(1);
  }
  char *input_data = malloc(2000 * sizeof(char));
  fgets(input_data, 2000, fptr);
  fclose(fptr);
  // get buf of all strings with dashes
  char **rangesBuf = malloc(500 * sizeof(char *));
  split_string(input_data, rangesBuf, ',', 2000);
  unsigned long invalidIdSums = 0;
  for (int rangesIdx = 0; rangesIdx < 500; rangesIdx++)
  {
    char *rangeStr = rangesBuf[rangesIdx];
    if (rangeStr == NULL)
    {
      break;
    }
    char **bufSubstring = malloc(4000 * sizeof(char *));
    split_string(rangeStr, bufSubstring, '-', 4000);
    // char *rangeStart = bufSubstring[0];
    // char *rangeEnd = bufSubstring[1];
    free(bufSubstring);
    free(rangeStr);
  }

  // get
  free(input_data);
}
