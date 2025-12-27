#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <strings.h>
#include "../include/string-utils.h"
#include "../include/math-utils.h"

int main(void)
{
  FILE *fptr = fopen("./day3/sample-data.txt", "r");
  long total = 0;
  size_t battery_size = 12;
  char line[500] = {0};
  while (fgets(line, 500, fptr))
  {
    line[strcspn(line, "\n")] = '\0';
    size_t lineLength = strlen(line);
    printf("%s\n", line);
    // array storing twelve chars to compare
    // get last twelve digits into separate string
    char slice[battery_size];
    create_slice(line, (int)lineLength - (int)battery_size, (int)lineLength, slice);
    printf("slice: %s\n", slice);
    // create digit arr and running max for battery value
    int digits[battery_size];
    convert_digits_to_int_array(slice, digits, battery_size);

    long max_battery = 0;
    long cur_battery = convert_digit_arr_to_long(digits, battery_size);
    printf("long: %ld\n", cur_battery);
    // i have two representations of the data, the long and the digits
    // i have to iterate backwards from the first index i havent seen yet
    size_t right = lineLength - battery_size - 1;
    printf("line length: %d\n", (int)lineLength);
    printf("beginning right should be 7: %c\n", line[right]);
    max_battery = cur_battery;
    printf("Right: %ld\n", right);
    size_t start = 0;
    while (right >= start && right < lineLength)
    {
      int new_num = line[right];
      // use digits 
      right--;
    }
    // max_battery = max_long(max_battery, cur_battery); break;
    total += max_battery;
    break;
  }
  // printf("Total: %d\n", total);
  fclose(fptr);
}
