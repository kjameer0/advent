#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

// #include "math_utils.h"
int add(int x, int y)
{
  return x + y;
}
static void test_add_basic(void **state)
{
  (void)state;
  assert_int_equal(add(2, 3), 5);
}

static void test_add_negative(void **state)
{
  (void)state;
  assert_int_equal(add(-2, 2), 0);
}

int main(void)
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_add_basic),
      cmocka_unit_test(test_add_negative),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
