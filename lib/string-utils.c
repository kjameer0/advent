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
    buf[bufIdx + 1] = NULL;
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
  if (startIdx >= endIdx || startIdx < 0 || endIdx > strlen(str))
  {
    return CREATE_SLICE_FAILURE;
  }
  memcpy(slice, str + startIdx, endIdx - startIdx);
  slice[endIdx - startIdx] = '\0';
  return CREATE_SLICE_SUCCESS;
}

bool is_valid(long num)
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
}
