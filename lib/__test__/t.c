#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

int rotate(char direction, int start, int magnitude)
{
  // start = start % 100;
  int finalPosition = 0;
  // printf("%s\n", "start");
  // printf("starting num: %d\n", start);
  // printf("magnitude num: %d\n", magnitude);
  if (direction == 'R')
  {
    finalPosition = (magnitude + start) % 100;
  }
  else
  {
    finalPosition = start - magnitude % 100;
    // printf("first subtraction: %d\n", finalPosition);
  }
  return finalPosition;
}

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
