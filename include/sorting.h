#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int sort(int arr[], size_t);
int sort_2d(unsigned long arr[][2], size_t row_num);
size_t merge_intervals(unsigned long arr[][2], size_t row_num);
void print_2d(unsigned long arr[][2], size_t row_num);

#endif
