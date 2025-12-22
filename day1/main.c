// Source - https://stackoverflow.com/a
// Posted by Oliver Charlesworth, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-12, License - CC BY-SA 3.0

#include <stdio.h>
#include "../include/string-utils.h" /* Include the header here, to obtain the function declaration */
#include <stdlib.h>
#include <string.h>

// // rotate the dial in a given direction by magnitude numbers starting from start
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
    finalPosition = (start - magnitude) % 100;
  }
  return finalPosition;
}
// extracts a number from a L43 type string
int extract_number(char str[])
{
  if (!str)
    return 0;
  char *rawDigits = malloc(strlen(str));
  // printf("%c", str[0]);
  for (unsigned long i = 1; i < strlen(str); i++)
  {
    if (str[i] == '\n')
      break;
    rawDigits[i - 1] = str[i];
  }
  int result = atoi(rawDigits);
  return result;
  // return 1;
}
int main(void)
{
  FILE *fptr;
  fptr = fopen("./day1/data.txt", "r");
  if (fptr == NULL)
  {
    printf("Not able to open the file.");
    exit(1);
  }
  char myString[6];
  int bufSize = 100000;
  char **lineBuf = malloc(bufSize * sizeof(*lineBuf));
  int curBufIdx = 0;
  while (fgets(myString, 6, fptr))
  {
    size_t len = strlen(myString) + 1;
    lineBuf[curBufIdx] = malloc(len);
    memcpy(lineBuf[curBufIdx], myString, len);
    curBufIdx++;
  };
  // core loop for problem logic
  // get direction and number
  // rotate lock
  // update password number
  int currentPosition = 50;
  int numberOfZeros = 0;
  printf("%s", "starting calculation\n");
  for (int idx = 0; idx < bufSize; idx++)
  {
    if (lineBuf[idx] == NULL)
    {
      break;
    }
    int num = extract_number(lineBuf[idx]);
    char direction = lineBuf[idx][0];
    currentPosition = rotate(direction, currentPosition, num);
    printf("original: %s, direction : %c num: %d\n", lineBuf[idx], direction, num);
    if (currentPosition == 0)
    {
      numberOfZeros++;
    }
    int crossover = num / 100;
    numberOfZeros += crossover;
  }
  printf("Number of zeroes: %d\n", numberOfZeros);

  fclose(fptr);
  // printf("%d", sizeof(int));
}
