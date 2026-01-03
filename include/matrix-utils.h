#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H
#include <stdbool.h>
#include <stddef.h>
// returns an int indicating how many cells contain "@" as opposed to "."
int count_forklift_cells(char **matrix, int row, int col, int num_rows, int num_cols, char target);

int get_start_row(int center_cell_row, int box_size);
int get_end_row(int center_cell_row, int box_size);

int get_start_col(int center_cell_col, int box_size);
int get_end_col(int center_cell_col, int box_size);

int replace_char_in_matrix(char **matrix, char to_replace, char replace_with, int num_rows, int num_cols);

#endif
