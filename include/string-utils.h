// Source - https://stackoverflow.com/a
// Posted by Oliver Charlesworth, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-12, License - CC BY-SA 3.0

#ifndef STRINGS_UTILS_H /* Include guard */
#define STRINGS_UTILS_H

#include <stdbool.h>

enum CreateSliceResult {
 CREATE_SLICE_SUCCESS,
 CREATE_SLICE_FAILURE,
 CREATE_SLICE_NOT_ENOUGH_BUFFER_SIZE,
};

int foo(int x); /* An example function declaration */

void split_string(const char str[], char **buf, char separator, int buf_size);

bool is_repeating_half(long num);

bool is_substring_repeating(const char *substring, const char *str);
// end idx is inclusive startIdx = 0 and endIdx = 2 gets first three chars
enum CreateSliceResult create_slice(const char *str, int startIdx, int endIdx, char slice[]);
#endif
