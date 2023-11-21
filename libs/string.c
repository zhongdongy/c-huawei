#include <string.h>
#include <stdio.h>
#include "./string.h"
#include "./sorting.h"
#include "./utils.h"

void str_sort_asc(char *str, int length)
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
    str[idx] = (char)temp[idx];
  }
}

void str_sort_desc(char *str, int length)
{
  int temp[length - 1];
  int idx;
  for (idx = 0; idx < length - 1; idx++)
  {
    temp[idx] = str[idx];
  }
  int temp1[] = {72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100, 33};
  quick_sort_desc(temp, length);
  for (idx = 0; idx < length - 1; idx++)
  {
    str[idx] = (char)temp[idx];
  }
}

char *s_gets(char *str, int n)
{
  char *ret_val;
  int i = 0;

  ret_val = fgets(str, n, stdin);

  if (ret_val)
  {
    while (str[i] != '\0' && str[i] != '\n')
    {
      i++;
    }

    if (str[i] == '\n')
    {
      str[i] = '\0';
    }
    else
    {
      while (getchar() != '\n')
      {
        continue;
      }
    }
  }

  return ret_val;
}