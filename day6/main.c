#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../include/string-utils.h"
#include "../include/math-utils.h"
#include "../include/sorting.h"

int main()
{
  const char *sample_path = "./day6/sample-data.txt";
  const size_t sample_number_of_lines = 4;
  const size_t sample_elements_per_line = 4;
  const size_t number_of_lines = 5;
  const size_t elements_per_line = 7000;
  const size_t chars_per_element = 6;
  const char *data_path = "./day6/data.txt";
  char matrix_buf[number_of_lines][elements_per_line][chars_per_element];

  FILE *fptr = fopen(data_path, "r");
  if (fptr == NULL)
  {
    perror("Failed to open file");
    exit(1);
  }
  char line[5000];
  size_t current_line = 0;
  while (fgets(line, 5000, fptr))
  {
    // printf("%s\n", line);
    char **buf_line = matrix_buf[current_line];
    split_string2(line, ' ', elements_per_line, chars_per_element, matrix_buf[current_line]);
    printf("%s\n", matrix_buf[current_line][0]);
    //turn everything in matrix-buf current line into a long
  }
  fclose(fptr);
}
