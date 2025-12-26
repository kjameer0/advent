#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <strings.h>
#include "../include/string-utils.h"
#include "../include/math-utils.h"

int main(void)
{
  FILE *fptr = fopen("./day3/data.txt", "r");
  char line[500] = {0};
  int total = 0;
  while (fgets(line, 500, fptr))
  {
    line[strcspn(line, "\n")] = '\0';
    int lineLength = (int)strlen(line);
    int right = lineLength - 2;
    // highest num we have seen thus far
    char curBatteryMaxRaw[2];
    create_slice(line, right + 1, right + 2, curBatteryMaxRaw);
    int curMaxBattery = 0;
    // pack raw string into int
    sscanf(curBatteryMaxRaw, "%d", &curMaxBattery);
    printf("Starting max: %d\n", curMaxBattery);
    int maxValue = 0;
    printf("line %s\n", line);
    while (right >= 0)
    {
      // extract part of string we need: a single digit
      char curBatteryRaw[2];
      create_slice(line, right, right + 1, curBatteryRaw);

      // place raw digit string currBatteryRaw into an int
      int curBatteryNum = 0;
      // pack raw string into int
      sscanf(curBatteryRaw, "%d", &curBatteryNum);
      // printf("Current battery Digit: %d\n", curBatteryNum);

      // make possible num out of current num and max and compart it to maxval

      int potentialMax = curBatteryNum * 10 + curMaxBattery;
      maxValue = max(potentialMax, maxValue);
      printf("Maximum result: %d\n Current: %d MaxOnright: %d", maxValue, curBatteryNum, curMaxBattery);
      if (curBatteryNum >= curMaxBattery)
      {
        curMaxBattery = curBatteryNum;
      }
      right--;
    }
    total += maxValue;
    printf("Max for line: %d\n", maxValue);
  }
  printf("Total: %d\n", total);
  fclose(fptr);
}
