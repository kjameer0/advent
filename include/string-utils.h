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
void split_string2(const char *str, char separator, size_t number_of_strings, size_t string_length, char buf[number_of_strings][string_length]);

bool is_repeating_half(long num);

bool is_substring_repeating(const char *substring, const char *str);
// end idx is inclusive startIdx = 0 and endIdx = 2 gets first three chars
enum CreateSliceResult create_slice(const char *str, int startIdx, int endIdx, char slice[]);

enum StringToIntArrayResult convert_digits_to_int_array(const char *digits, int output_buf[], int buf_size);

int index_of(int *arr, int target, size_t len);
int index_of_lu(unsigned long *arr, unsigned long target, size_t len);
int find_smallest(int *arr, size_t len);
int splice_arr(int arr[], int target_idx, size_t len);
int unshift_array(int arr[], int value, size_t len);
int find_next_smaller_idx(int arr[], int value, size_t len);

unsigned long convert_digit_arr_to_long(int *digits, size_t len);

// try to insert a new value into an array
// if that value is new greatest or the same as the greatest
// add to front and remove the first number
// before an increasing number
int elevate_arr(int arr[], int new_num, size_t arr_size);

#endif
