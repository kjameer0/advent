#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <strings.h>
#include "../include/string-utils.h"
#include "../include/math-utils.h"

int main(void)
{
  FILE *fptr = fopen("./day3/data.txt", "r");
  unsigned long total = 0;
  size_t battery_size = 12;
  char line[500] = {0};
  while (fgets(line, 500, fptr))
  {
    line[strcspn(line, "\n")] = '\0';
    size_t lineLength = strlen(line);
    // array storing twelve chars to compare
    // get last twelve digits into separate string
    char slice[battery_size];
    create_slice(line, (int)lineLength - (int)battery_size, (int)lineLength, slice);
    // printf("slice: %s\n", slice);
    // create digit arr and running max for battery value
    int digits[battery_size];
    convert_digits_to_int_array(slice, digits, battery_size);

    unsigned long max_battery = 0;
    unsigned long cur_battery = convert_digit_arr_to_long(digits, battery_size);
    printf("long: %lu\n", cur_battery);
    // i have two representations of the data, the long and the digits
    // i have to iterate backwards from the first index i havent seen yet
    size_t right = lineLength - battery_size - 1;
    max_battery = cur_battery;
    size_t start = 0;
    while (right >= start && right < lineLength)
    {
      int new_num = line[right] - '0';
      // use digits
      // printf("new num: %d\n", new_num);
      int res = elevate_arr(digits, new_num, battery_size);
      if (res == -1)
      {
        exit(1);
      }
      // printf("old battery value: %ld\n", cur_battery);
      unsigned long new_battery = convert_digit_arr_to_long(digits, battery_size);
      if (new_battery > max_battery)
      {
        max_battery = new_battery;
      }
      // printf("New battery value: %ld\n", new_battery);
      right--;
    }
    printf("Max battery for line %s: %lu\n", line, max_battery);
    total += max_battery;
  }
  printf("Total: %lu\n", total);
  fclose(fptr);
}
