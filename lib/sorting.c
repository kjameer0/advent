#include "../include/sorting.h"
#include "../include/math-utils.h"
#include <stddef.h>
#include <stdbool.h>
void print_2d(unsigned long arr[][2], size_t row_num)
{
  for (size_t idx = 0; idx < row_num; idx++)
  {
    unsigned long start_val = arr[idx][0];
    unsigned long end_val = arr[idx][1];
    printf("Idx: %lu Start: %lu End: %lu\n", idx, start_val, end_val);
  }
}
int sort(int arr[], size_t size)
{
  while (true)
  {
    bool did_swap = false;
    size_t idx = 0;
    while (idx < size - 1)
    {
      int cur = arr[idx];
      int next = arr[idx + 1];
      if (cur > next)
      {
        int temp = cur;
        arr[idx] = next;
        arr[idx + 1] = temp;
        did_swap = true;
      }
      idx++;
    }
    if (!did_swap)
    {
      return 0;
    }
  }
  return 0;
}
// sort based on 0th index of 2d array
int sort_2d(unsigned long arr[][2], size_t row_num)
{
  while (true)
  {
    bool did_swap = false;
    size_t idx = 0;
    while (idx < row_num - 1)
    {
      // get start of each range we are comparing
      unsigned long cur = arr[idx][0];
      unsigned long next = arr[idx + 1][0];
      unsigned long cur_end = arr[idx][1];
      unsigned long next_end = arr[idx + 1][1];
      if (cur > next)
      {
        unsigned long tempStart = arr[idx][0];
        unsigned long tempEnd = arr[idx][1];
        arr[idx][0] = arr[idx + 1][0];
        arr[idx][1] = arr[idx + 1][1];
        arr[idx + 1][0] = tempStart;
        arr[idx + 1][1] = tempEnd;
        did_swap = true;
      }
      else if (cur == next)
      {
        if (cur_end <= next_end)
        {
          idx++;
          continue;
        }
        printf("******\n");
        // printf("******\n");
        unsigned long tempStart = arr[idx][0];
        unsigned long tempEnd = arr[idx][1];
        arr[idx][0] = arr[idx + 1][0];
        arr[idx][1] = arr[idx + 1][1];
        arr[idx + 1][0] = tempStart;
        arr[idx + 1][1] = tempEnd;
        did_swap = true;
      }
      idx++;
    }
    if (!did_swap)
    {
      return 0;
    }
  }
  return 0;
}

// modifies an array of unsigned longs and returns the new size
size_t merge_intervals(unsigned long arr[][2], size_t row_num)
{
  if (row_num <= 1)
  {
    return 0;
  }
  size_t final_row_num = row_num;
  sort_2d(arr, row_num);
  print_2d(arr, row_num);

  // ranges are sorted by start,

  unsigned long (*currentRange)[2] = &(arr[0]);
  // number of elements that are valid post return
  size_t placement = 0;
  for (size_t idx = 0; idx < row_num - 1; idx++)
  {
    // if next interval's small is less than current's end
    // make current's end next's end

    unsigned long curStart = (*currentRange)[0];
    unsigned long curEnd = (*currentRange)[1];
    unsigned long nextStart = arr[idx + 1][0];
    unsigned long nextEnd = arr[idx + 1][1];

    if (nextStart <= curEnd)
    {
      (*currentRange)[1] = max_unsigned_long(nextEnd, curEnd);
      final_row_num -= 1;
    }
    else
    {
      arr[placement][0] = (*currentRange)[0];
      arr[placement][1] = (*currentRange)[1];
      placement++;
      currentRange = &(arr[idx + 1]);
    }
  }
  arr[placement][0] = (*currentRange)[0];
  arr[placement][1] = (*currentRange)[1];
  return final_row_num;
}
