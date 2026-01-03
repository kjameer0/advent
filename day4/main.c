#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "../include/matrix-utils.h"
int main()
{
  FILE *fptr = fopen("./day4/data.txt", "r");
  char line[500];
  int row_num = 0;
  // change these values if the input file changes
  const int line_length = 139;
  const int number_of_lines = 139;
  char *lines[number_of_lines];
  int current_line = 0;
  while (fgets(line, 500, fptr))
  {
    line[strcspn(line, "\n")] = '\0';
    char *copied_line = malloc(line_length);
    strcpy(copied_line, line);
    lines[current_line] = copied_line;
    current_line++;
  }
  // lines data should be in matrix form
  int total_reachable_forklift_count = 0;
  count_forklift_cells(lines, 0, 0, number_of_lines, line_length, '@');
  for (int r = 0; r < number_of_lines; r++)
  {
    for (int c = 0; c < line_length; c++)
    {
      total_reachable_forklift_count += count_forklift_cells(lines, r, c, number_of_lines, line_length, '@');
    }
  }
  printf("Total reachable forklifts: %d\n", total_reachable_forklift_count);
  int total_can_remove = 0;
  while (total_reachable_forklift_count > 0)
  {
    // clean every x and plus one to total_can_remove

    int replaced = replace_char_in_matrix(lines, 'x', '.', number_of_lines, line_length);
    printf("%s\n", lines[0]);
    total_reachable_forklift_count = 0;
    total_can_remove += replaced;
    for (int r = 0; r < number_of_lines; r++)
    {
      for (int c = 0; c < line_length; c++)
      {
        total_reachable_forklift_count += count_forklift_cells(lines, r, c, number_of_lines, line_length, '@');
      }
    }

  }
  printf("replaceable: %d\n", total_can_remove);
  for (int idx = 0; idx < number_of_lines; idx++)
  {
    free(lines[idx]);
  }
}
