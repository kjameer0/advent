// Source - https://stackoverflow.com/a
// Posted by Oliver Charlesworth, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-12, License - CC BY-SA 3.0

#ifndef STRINGS_UTILS_H /* Include guard */
#define STRINGS_UTILS_H

#include <stdbool.h>
#include <stddef.h>

enum StringToIntArrayResult
{
  STRING_TO_INT_ARRAY_SUCCESS,
  STRING_TO_INT_ARRAY_FAILURE,
  STRING_TO_INT_ARRAY_BUF_SIZE_TOO_SMALL
};
enum CreateSliceResult
{
  CREATE_SLICE_SUCCESS,
  CREATE_SLICE_FAILURE,
  CREATE_SLICE_NOT_ENOUGH_BUFFER_SIZE,
};
bool is_valid_id(long num);

bool is_repeating_continuous(const char *substring, const char *str);
int foo(int x);

void split_string(const char str[], char **buf, char separator, int buf_size);

bool is_repeating_half(long num);

bool is_substring_repeating(const char *substring, const char *str);
// end idx is inclusive startIdx = 0 and endIdx = 2 gets first three chars
enum CreateSliceResult create_slice(const char *str, int startIdx, int endIdx, char slice[]);

enum StringToIntArrayResult convert_digits_to_int_array(const char *digits, int output_buf[], int buf_size);

int index_of(int *arr, int target, size_t len);
int find_smallest(int *arr, size_t len);
int splice_arr(int arr[], int target, size_t len);
int unshift_array(int arr[], int value, size_t len);
int find_next_smaller_idx(int arr[], int value, size_t len);
#endif
