#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../include/math-utils.h"
#include "../../include/string-utils.h"
#include <stdlib.h>
#include <stdbool.h>
// #include "math_utils.h"
int add(int x, int y)
{
  return x + y;
}

static void test_get_zeroes_for_rotation(void **state)
{
  (void)state;
  assert_int_equal(get_zeroes_for_rotation('R', 50, 500), 5);
  assert_int_equal(get_zeroes_for_rotation('R', 50, 550), 6);
  assert_int_equal(get_zeroes_for_rotation('L', 50, 550), 6);
  assert_int_equal(get_zeroes_for_rotation('L', 3, 98), 1);
  assert_int_equal(get_zeroes_for_rotation('L', 0, 101), 1);
  assert_int_equal(get_zeroes_for_rotation('R', 0, 101), 1);
  assert_int_equal(get_zeroes_for_rotation('R', 38, 45), 0);
  assert_int_equal(get_zeroes_for_rotation('R', 38, 195), 2);
  assert_int_equal(get_zeroes_for_rotation('L', 38, 195), 2);
  assert_int_equal(get_zeroes_for_rotation('L', 51, 34), 0);
}

static void test_split_string(void **state)
{
  (void)state;
  char **buf = malloc(1000 * sizeof(char *));
  const char *base_str = "11-22,95-115,998-1012,1188511880-1188511890,222220-222224,1698522-1698528,446443-446449,38593856-38593862,565653-565659,824824821-824824827,2121212118-2121212124";
  split_string(base_str, buf, ',', 1000);
  assert_string_equal(buf[0], "11-22");
  assert_string_equal(buf[1], "95-115");
  assert_string_equal(buf[10], "2121212118-2121212124");
  const char *substring1 = "2121212118-2121212124";
  char **bufSubstring = malloc(1000 * sizeof(char *));
  split_string(substring1, bufSubstring, '-', 1000);
  assert_string_equal(bufSubstring[0], "2121212118");
  assert_string_equal(bufSubstring[1], "2121212124");
}

static void test_is_repeating_half(void **state)
{
  (void)state;
  assert_int_equal(is_repeating_half(101), 0);
  assert_int_equal(is_repeating_half(1010), 1);
  assert_int_equal(is_repeating_half(2121212118), 0);
  assert_int_equal(is_repeating_half(24), 0);
  assert_int_equal(is_repeating_half(25), 0);
  assert_int_equal(is_repeating_half(26), 0);
  assert_int_equal(is_repeating_half(27), 0);
  assert_int_equal(is_repeating_half(33), 1);
}

static void test_rotate(void **state)
{
  (void)state;
  assert_int_equal(rotate('R', 0, 1), 1);
  assert_int_equal(rotate('R', 0, 1), 1);
  assert_int_equal(rotate('L', 0, 1), 99);
}
static void test_create_slice(void **state)
{
  (void)state;
  char *output = malloc(50 * sizeof(char));
  enum CreateSliceResult result = create_slice("hello", 1, 4, output);
  assert_true(result == CREATE_SLICE_SUCCESS);
  assert_string_equal(output, "ell");
  char *output2 = malloc(50 * sizeof(char));
  enum CreateSliceResult improperSlice = create_slice("hello", 0, 10, output);
  assert_true(improperSlice == CREATE_SLICE_FAILURE);

}

int main(void)
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_get_zeroes_for_rotation),
      cmocka_unit_test(test_rotate),
      cmocka_unit_test(test_split_string),
      cmocka_unit_test(test_is_repeating_half),
      cmocka_unit_test(test_create_slice)};

  return cmocka_run_group_tests(tests, NULL, NULL);
}
