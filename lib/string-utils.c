#include "../include/string-utils.h" /* Include the header (not strictly necessary here) */
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int foo(int x) /* Function definition */
{
  return x + 5;
}

void split_string(const char str[], char **buf, char separator, int buf_size)
{
  int left = 0;
  int bufIdx = 0;
  for (int right = 0; right <= strlen(str); right++)
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
    left = right + 1;
    bufIdx++;
  }
}
// checks if a string a
bool is_repeating_half(int num)
{
  char stringified_number[80];
  sprintf(stringified_number, "%d", num);
  int len = strlen(stringified_number);
  if (len % 2 == 1)
  {
    return false;
  }
  for(int idx = 0; idx < len/2; idx++) {
    char leftChar = stringified_number[idx];
    char rightChar = stringified_number[idx + (len/2)];
    if (leftChar != rightChar) {
      return false;
    }
  }
  return true;
}
