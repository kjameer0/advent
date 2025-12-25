#include <stdio.h>
#include <stdlib.h>
#include "../include/string-utils.h"

int main()
{
  FILE *fptr = fopen("./day2/data.txt", "r");
  if (fptr == NULL)
  {

    printf("Not able to open the file");
    exit(1);
  }
  char *input_data = malloc(2000 * sizeof(char));
  fgets(input_data, 2000, fptr);
  fclose(fptr);
  // get buf of all strings with dashes
  char **rangesBuf = malloc(1000 * sizeof(char *));
  split_string(input_data, rangesBuf, ',', 2000);
  unsigned long invalidIdSums = 0;
  for (int rangesIdx = 0; rangesIdx < 1000; rangesIdx++)
  {
    char *rangeStr = rangesBuf[rangesIdx];
    if (rangeStr == NULL)
    {
      break;
    }
    char **bufSubstring = malloc(4000 * sizeof(char *));
    split_string(rangeStr, bufSubstring, '-', 4000);
    // printf("start of range:  %s\n", bufSubstring[0]);
    // printf("end of range:  %s\n", bufSubstring[1]);
    long rangeStart = strtol(bufSubstring[0], NULL, 10);
    long rangeEnd = strtol(bufSubstring[1], NULL, 10);
    for (long currentId = rangeStart; currentId <= rangeEnd; currentId++)
    {
      printf("%ld\n", currentId);
      if (is_repeating_half(currentId))
      {
        invalidIdSums += (long)currentId;
      }
    }
    free(bufSubstring);
    free(rangeStr);
    // break;
  }
  printf("Total = %ld\n", invalidIdSums);
  free(input_data);
}
