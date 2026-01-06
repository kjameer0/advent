#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../include/string-utils.h"
#include "../include/math-utils.h"
#include "../include/sorting.h"

int main()
{
  const char *sample_path = "./day6/sample-data.txt";
  const char *data_path = "./day6/data.txt";

  FILE *fptr = fopen(data_path, "r");
  if (fptr == NULL)
  {
    perror("Failed to open file");
    exit(1);
  }
  char line[4000];
  while (fgets(line, 4000, fptr))
  {
    printf("%s\n", line);
  }
  fclose(fptr);
}
