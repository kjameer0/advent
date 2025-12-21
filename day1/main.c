// Source - https://stackoverflow.com/a
// Posted by Oliver Charlesworth, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-12, License - CC BY-SA 3.0

#include <stdio.h>
#include "../include/string-utils.h" /* Include the header here, to obtain the function declaration */
#include <stdlib.h>
#include <string.h>

// int rotate(char direction, )
// extracts a number from a L43 type string
int extract_number(char str[])
{
  // char *rawDigits = malloc(strlen(str) + 1);
  // printf("%c", str[0]);
  // for (unsigned long i = 1; i < strlen(str); i++)
  // {
  //   if (str[i] == "\n")
  //     break;
  //   rawDigits[i - 1] = str[i];
  // }
  // int result = atoi(rawDigits);
  // return result;
  return 1;
}
int main(void)
{
  FILE *fptr;
  fptr = fopen("./day1/sample_data.txt", "r");
  if (fptr == NULL)
  {
    printf("Not able to open the file.");
    exit(1);
  }
  char myString[5];
  int bufSize = 1000;
  char *lineBuf[5] = malloc(bufSize * sizeof(*lineBuf));
  int curBufIdx = 0;
  while (fgets(myString, 5, fptr))
  {
    // printf("cur idx: %d\n", curBufIdx);
    lineBuf[curBufIdx] = malloc(strlen(myString) + 1);
    printf("%lu", sizeof myString);
    memcpy(lineBuf[curBufIdx], myString, sizeof myString);
    printf("%lu", sizeof lineBuf[curBufIdx]);
    // // lineBuf[curBufIdx] = str;
    // printf("%p\n", lineBuf[curBufIdx]);
    curBufIdx++;
  };
  for (int idx = 0; idx < bufSize; idx++)
  {
    int num = extract_number(lineBuf[bufSize]);
    if (lineBuf[idx] == NULL)
    {
      break;
    }
    // printf("%s", lineBuf[idx]);
    // printf("%d", num);
  }
  for (int i = 0; i < curBufIdx; i++)
  {
    free(lineBuf[i]);
  }
  free(lineBuf);
  fclose(fptr);
  // printf("%s", myString);
}
