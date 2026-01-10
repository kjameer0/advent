#ifndef MATH_UTILS_H
#define MATH_UTILS_H
#include <stdio.h>

int foo2(int x);
int get_zeroes_for_rotation(char direction, int start, int magnitude);
int rotate(char direction, int start, int magnitude);

int max(int num1, int num2);
int max_long(long num1, long num2);
unsigned long max_unsigned_long(unsigned long num1, unsigned long num2);

//given an array of longs, perform an operation all of those numbers
// operation can be + or *
long perform_multiple_operations(long *nums, size_t number_count, char operation);
#endif
