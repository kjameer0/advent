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
  enum CreateSliceResult improperSlice = create_slice("hello", 0, 10, output2);
  assert_true(improperSlice == CREATE_SLICE_FAILURE);

  char *output3 = malloc(50 * sizeof(char));
  enum CreateSliceResult result3 = create_slice("hello", 0, 1, output3);
  assert_true(result3 == CREATE_SLICE_SUCCESS);
  assert_string_equal(output3, "h");
}

static void test_is_valid_id(void **state)
{
  (void)state;
  long invalidNum1 = 2894097257;
  assert_false(is_valid_id(invalidNum1));

  long validNum1 = 2020;
  assert_true(is_valid_id(validNum1));

  long validNum2 = 20202020;
  assert_true(is_valid_id(validNum2));

  long invalidNum2 = 20202;
  assert_false(is_valid_id(invalidNum2));

  long validNum3 = 999;
  assert_true(is_valid_id(validNum3));
}

static void test_convert_digits_to_int_array(void **state)
{
  (void)state;
  int buf[12] = {0};
  enum StringToIntArrayResult res = convert_digits_to_int_array("123456123456", buf, 12);
  assert_true(res == STRING_TO_INT_ARRAY_SUCCESS);
  assert_int_equal(buf[0], 1);
  assert_int_equal(buf[11], 6);
}

static void test_is_repeating_continuous(void **state)
{
  (void)state;
  const char *correctInput1 = "hehe";
  assert_true(is_repeating_continuous("he", correctInput1));
  assert_false(is_repeating_continuous("h", correctInput1));

  const char *correctInput2 = "123123";
  assert_true(is_repeating_continuous("123", correctInput2));
  assert_false(is_repeating_continuous("12", correctInput2));
}

static void test_index_of(void **state)
{
  (void)state;
  int arr[] = {1, 6, 5};
  assert_int_equal(index_of(arr, 6, 3), 1);
  assert_int_equal(index_of(arr, 3, 3), -1);
}
static void test_unshift_array(void **state)
{
  (void)state;
  int arr[] = {1, 6, 5};
  assert_int_equal(unshift_array(arr, 5, 3), 0);
  assert_int_equal(arr[0], 5);
}

int main(void)
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_get_zeroes_for_rotation),
      cmocka_unit_test(test_rotate),
      cmocka_unit_test(test_split_string),
      cmocka_unit_test(test_is_repeating_half),
      cmocka_unit_test(test_create_slice),
      cmocka_unit_test(test_is_valid_id),
      cmocka_unit_test(test_is_repeating_continuous),
      cmocka_unit_test(test_convert_digits_to_int_array),
      cmocka_unit_test(test_index_of),
      cmocka_unit_test(test_unshift_array),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
