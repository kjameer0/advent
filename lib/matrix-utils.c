#include "../include/matrix-utils.h" /* Include the header (not strictly necessary here) */
#include "../include/string-utils.h"
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

int count_forklift_cells(char **matrix, int row, int col, int num_rows, int num_cols, char target)
{
  // width and height of box to check
  if (matrix[row][col] == '.')
  {
    return 0;
  }
  int box_size = 3;

  int start_row = get_start_row(row, box_size);
  int end_row = get_end_row(row, box_size);
  int start_col = get_start_col(col, box_size);
  int end_col = get_end_col(col, box_size);

  int target_char_count = 0;
  for (int r = start_row; r <= end_row; r++)
  {
    for (int c = start_col; c <= end_col; c++)
    {
      if (r < 0 || c < 0)
      {
        // printf("exceeded negativeBounds\n");
        continue;
      }
      if (r >= num_rows || c >= num_cols)
      {
        // printf("exceeded Positive Bounds\n");
        continue;
      }
      if (r == row && c == col)
      {
        continue;
      }
      char cur_cell = matrix[r][c];
      if (cur_cell == target || cur_cell == 'x')
      {
        target_char_count++;
      }
      // printf("Current Cell: %c\n", cur_cell);
    }
  }
  if (target_char_count >= 4)
  {
    // printf("Fail: row %d col %d\n", row, col);
    // printf("target_char count: %d\n", target_char_count);
    return 0;
  }
  else
  {
    // printf("Success: row %d col %d\n", row, col);
    // printf("target_char count: %d\n", target_char_count);
    matrix[row][col] = 'x';
    return 1;
  };
}
int replace_char_in_matrix(char **matrix, char to_replace, char replace_with, int num_rows, int num_cols)
{
  int replaced = 0;
  for (int r = 0; r < num_rows; r++)
  {
    for (int c = 0; c < num_cols; c++)
    {
      if (matrix[r][c] == to_replace)
      {
        matrix[r][c] = replace_with;
        replaced++;
      }
    }
  }
  return replaced;
}
int get_start_row(int center_cell_row, int box_size)
{
  return center_cell_row - (box_size / 2);
}
int get_end_row(int center_cell_row, int box_size)
{
  return center_cell_row + (box_size / 2);
}

int get_start_col(int center_cell_col, int box_size)
{
  return center_cell_col - (box_size / 2);
}
int get_end_col(int center_cell_col, int box_size)
{
  return center_cell_col + (box_size / 2);
}
