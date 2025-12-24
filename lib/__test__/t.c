#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../include/math-utils.h"
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

static void test_rotate(void **state)
{
  (void)state;
  assert_int_equal(rotate('R', 0, 1), 1);
  assert_int_equal(rotate('R', 0, 1), 1);
  assert_int_equal(rotate('L', 0, 1), 99);
}
int main(void)
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_get_zeroes_for_rotation),
      cmocka_unit_test(test_rotate)};

  return cmocka_run_group_tests(tests, NULL, NULL);
}
