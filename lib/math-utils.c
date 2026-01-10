#include "../include/math-utils.h" /* Include the header (not strictly necessary here) */
#include <stdio.h>
int foo2(int x) /* Function definition */
{
  return x + 5;
}

long perform_multiple_operations(long *nums, size_t number_count, char operation)
{
  if (number_count == 0)
  {
    return 0;
  }
  int total = nums[0];
  for (size_t idx = 1; idx < number_count; idx++)
  {
    switch (operation)
    {
    case '*':
      /* code */
      total *= nums[idx];
      break;
    case '+':
      total += nums[idx];
    default:
      break;
    }
  }
  return total;
}

int rotate(char direction, int start, int magnitude)
{

  // start = start % 100;
  int finalPosition = 0;
  // printf("starting num: %d\n", start);
  // printf("magnitude num: %d\n", magnitude);
  if (direction == 'R')
  {
    finalPosition = (magnitude + start) % 100;
  }
  else
  {
    // if (start - magnitude < )
    int difference = start - magnitude;
    if (difference < 0)
    {
      difference = 100 + difference;
    }
    finalPosition = difference;
  }
  return finalPosition;
}
int get_zeroes_for_rotation(char direction, int start, int magnitude)
{
  int crossover = magnitude / 100;
  int numberOfZeros = crossover;
  magnitude -= 100 * crossover;
  if (start == 0)
  {
    return numberOfZeros;
  }
  if (direction == 'R')
  {
    if (start + magnitude >= 100)
    {
      numberOfZeros++;
    }
  }
  else
  {
    if (start - magnitude <= 0)
    {
      numberOfZeros++;
    }
  }
  return numberOfZeros;
}
int max(int num1, int num2)
{
  if (num1 >= num2)
  {
    return num1;
  }
  return num2;
}

int max_long(long num1, long num2)
{
  if (num1 >= num2)
  {
    return num1;
  }
  return num2;
}
unsigned long max_unsigned_long(unsigned long num1, unsigned long num2)
{
  if (num1 >= num2)
  {
    return num1;
  }
  return num2;
}
