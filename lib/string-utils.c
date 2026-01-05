#include "../include/string-utils.h" /* Include the header (not strictly necessary here) */
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

int foo(int x) /* Function definition */
{
  return x + 5;
}

void split_string(const char str[], char **buf, char separator, int buf_size)
{
  int left = 0;
  int bufIdx = 0;
  if (strlen(str) > buf_size)
  {
    perror("Buffer too large");
    exit(1);
  }
  size_t len = strlen(str);
  for (int right = 0; right <= len; right++)
  {
    char currentChar = str[right];
    if (currentChar != separator && right != strlen(str))
    {
      continue;
    }
    char *substring = malloc(right - left + 1);
    memcpy(substring, str + left, right - left);
    substring[right - left] = '\0';
    buf[bufIdx] = substring;
    // buf[bufIdx + 1] = NULL;
    left = right + 1;
    bufIdx++;
  }
}
// checks if a string a
bool is_repeating_half(long num)
{
  char stringified_number[80];
  sprintf(stringified_number, "%ld", num);
  size_t size = strlen(stringified_number);
  if (size > INT_MAX)
  {
    perror("string size to large to convert to int");
    exit(1);
  }
  int len = (int)size;
  if (len % 2 == 1)
  {
    return false;
  }
  for (int idx = 0; idx < len / 2; idx++)
  {
    char leftChar = stringified_number[idx];
    char rightChar = stringified_number[idx + (len / 2)];
    if (leftChar != rightChar)
    {
      return false;
    }
  }
  // printf("Valid number: %ld\n", num);
  return true;
}

enum CreateSliceResult create_slice(const char *str, int startIdx, int endIdx, char slice[])
{
  if (startIdx > endIdx || startIdx < 0 || endIdx > strlen(str))
  {
    return CREATE_SLICE_FAILURE;
  }
  memcpy(slice, str + startIdx, endIdx - startIdx);
  slice[endIdx - startIdx] = '\0';
  return CREATE_SLICE_SUCCESS;
}

bool is_valid_id(long num)
{
  char stringified_number[80];
  sprintf(stringified_number, "%ld", num);
  size_t size = strlen(stringified_number);
  if (size > INT_MAX)
  {
    perror("string size to large to convert to int");
    exit(1);
  }
  int len = (int)size;
  // create larger and larger slices
  int sliceSize = 1;
  // iterate from 0 to half size of stringed number
  // make a string of slice size
  // check if that string is repeating
  for (int idx = 0; idx < len / 2; idx++)
  {
    char *slice = malloc(sliceSize + 1);
    enum CreateSliceResult result = create_slice(stringified_number, 0, sliceSize, slice);
    if (is_repeating_continuous(slice, stringified_number))
    {
      return true;
    }
    free(slice);
    sliceSize++;
  }
  return false;
}

// checks if a small string is repeating for the entirety of another string
bool is_repeating_continuous(const char *substring, const char *str)
{
  int len = (int)strlen(str);
  int mod = (int)strlen(substring);
  if (len % mod != 0)
  {
    return false;
  }
  for (int idx = 0; idx < len; idx++)
  {
    if (substring[idx % mod] != str[idx])
    {
      return false;
    }
  }
  return true;
}

enum StringToIntArrayResult convert_digits_to_int_array(const char *digits, int output_buf[], int buf_size)
{
  int digit_len = strlen(digits);
  if (buf_size < digit_len)
  {
    return STRING_TO_INT_ARRAY_BUF_SIZE_TOO_SMALL;
  }
  for (int idx = 0; idx < digit_len; idx++)
  {
    int converted_digit = digits[idx] - '0';
    output_buf[idx] = converted_digit;
  }
  return STRING_TO_INT_ARRAY_SUCCESS;
}

int index_of(int *arr, int target, size_t len)
{
  for (size_t i = 0; i < len; i++)
  {
    if (arr[i] == target)
    {
      return (int)i;
    }
  }
  return -1;
}
int index_of_lu(unsigned long *arr, unsigned long target, size_t len)
{
  for (size_t i = 0; i < len; i++)
  {
    if (arr[i] == target)
    {
      return (int)i;
    }
  }
  return -1;
}

int find_smallest(int *arr, size_t len)
{
  int cur_max = arr[0];
  for (size_t i = 0; i < len; i++)
  {
    if (arr[i] < cur_max)
    {
      cur_max = arr[i];
    }
  }
  return cur_max;
}

int splice_arr(int arr[], int target_idx, size_t len)
{
  for (size_t idx = target_idx; idx < len - 1; idx++)
  {
    arr[idx] = arr[idx + 1];
  }
  return 0;
}

// insert value at an index and move all subsequent values to the right
// 1,2,3   4
// 4 1 2
int unshift_array(int arr[], int value, size_t len)
{
  int temp = arr[0];
  int temp2 = arr[0];
  for (size_t idx = 1; idx < len; idx++)
  {
    temp2 = arr[idx];
    arr[idx] = temp;
    temp = temp2;
  }
  arr[0] = value;
  return 0;
}

int find_next_smaller_idx(int arr[], int value, size_t len)
{
  for (size_t idx = 0; idx < len; idx++)
  {
    if (arr[idx] < value)
    {
      return idx;
    }
  }
  return -1;
}

unsigned long convert_digit_arr_to_long(int *digits, size_t len)
{
  unsigned long total = 0;
  for (size_t idx = 0; idx < len; idx++)
  {
    unsigned long cur = (unsigned long)digits[idx];
    total += cur;
    if (idx < len - 1)
    {
      total *= 10;
    }
  }
  return total;
}

int elevate_arr(int arr[], int new_num, size_t arr_size)
{
  // find idx to remove
  if (new_num == 1 || new_num < arr[0])
  {
    return 0;
  }
  size_t idx_to_remove = 0;
  for (size_t idx = 0; idx < arr_size - 1; idx++)
  {
    int cur = arr[idx];
    int next = arr[idx + 1];
    if (cur < next || cur == 1)
    {
      idx_to_remove = idx;
      int res = splice_arr(arr, (int)idx_to_remove, arr_size);
      if (res == -1)
      {
        perror("Failed to splice digits");
        return -1;
      }
      int unshift_result = unshift_array(arr, new_num, arr_size);
      return 0;
    }
  }
  int unshift_result = unshift_array(arr, new_num, arr_size);
  return 0;
}

void split_string_no_allocation(const char *str[], char **buf, char separator, size_t buf_size)
{
  int left = 0;
  int bufIdx = 0;
  size_t len = strlen(str);
  if (strlen(str) > buf_size)
  {
    perror("Buffer too large");
    exit(1);
  }
  for (int right = 0; right <= len; right++)
  {
    char currentChar = str[right];
    if (currentChar != separator && right != strlen(str))
    {
      continue;
    }
    char *substring = malloc(right - left + 1);
    memcpy(substring, str + left, right - left);
    substring[right - left] = '\0';
    buf[bufIdx] = substring;
    // buf[bufIdx + 1] = NULL;
    left = right + 1;
    bufIdx++;
  }
}
