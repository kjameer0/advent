#include "../include/math-utils.h" /* Include the header (not strictly necessary here) */

int foo2(int x) /* Function definition */
{
  return x + 5;
}

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
