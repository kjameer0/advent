#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../include/string-utils.h"
#include "../include/math-utils.h"
#include "../include/sorting.h"

int main()
{
  const int sample_ranges = 4;
  const int real_ranges = 186;
  const int NUMBER_OF_IDS = 1000;
  const int NUMBER_OF_RANGES = real_ranges;
  FILE *rangesFptr = fopen("day5/data-ranges.txt", "r");
  FILE *idsFptr = fopen("day5/data-ids.txt", "r");
  if (rangesFptr == NULL)
  {
    perror("Failed to open ranges");
    exit(1);
  }
  if (idsFptr == NULL)
  {
    perror("Failed to open ids");
    exit(1);
  }
  const int LINE_SIZE = 2000;
  char rawId[LINE_SIZE];
  unsigned long *ids[NUMBER_OF_IDS];
  int idx = 0;
  while (fgets(rawId, LINE_SIZE, idsFptr))
  {
    // read out the string and copy it into id
    rawId[strcspn(rawId, "\n")] = '\0';
    unsigned long num_id = strtol(strdup(rawId), NULL, 10);
    ids[idx] = &num_id;
    idx++;
  }

  char rawRange[LINE_SIZE];
  unsigned long ranges[NUMBER_OF_RANGES][2];
  int unspoiled_ids = 0;
  unsigned long total_unspoiled_ids = 0;
  size_t range_idx = 0;
  // TODO: create array of arrays containing ranges to then sort
  while (fgets(rawRange, LINE_SIZE, rangesFptr))
  {
    char *rangeElements[3];
    split_string(rawRange, rangeElements, '-', 5000);
    const char *rangeStart = rangeElements[0];
    const char *rangeEnd = rangeElements[1];
    // printf("Range Start: %s, Range End: %s\n", rangeStart, rangeEnd);
    const unsigned long rangeStartNum = strtol(rangeStart, NULL, 10);
    const unsigned long rangeEndNum = strtol(rangeEnd, NULL, 10);
    ranges[range_idx][0] = rangeStartNum;
    ranges[range_idx][1] = rangeEndNum;
    free(rangeElements[0]);
    free(rangeElements[1]);
    // print_2d(ranges, range_idx + 1);
    range_idx++;
  }
  // print_2d(ranges, NUMBER_OF_RANGES);
  size_t interval_count = merge_intervals(ranges, NUMBER_OF_RANGES);
  printf("Interval Count: %lu", interval_count);
  // sort the ranges by first
  unsigned long fresh_ids = 0;
  for (size_t idx = 0; idx < interval_count; idx++)
  {
    fresh_ids += ranges[idx][1] - ranges[idx][0] + 1;
  }
  printf("total fresh ids: %lu\n", fresh_ids);

  return 0;
}
