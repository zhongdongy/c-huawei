#include "./string.h"
#include "./sorting.h"
#include "./utils.h"

void str_sort(char *str, int length)
{
  int temp[length - 1];
  int idx;
  for (idx = 0; idx < length - 1; idx++)
  {
    temp[idx] = str[idx];
  }
  quick_sort_asc(temp, length);

  for (idx = 0; idx < length - 1; idx++)
  {
    str[idx] = (char) temp[idx];
  }
}